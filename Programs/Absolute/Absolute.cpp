#include "Utils/Common.hpp"
#include "Utils/Unix.hpp"

struct Exec
{
    fs::path path_executable, path_description;
    string name_program;

    Exec(string name_program) : name_program(name_program) {}

    const string &getName()
    {
        if (path_executable.empty())
        {
            cerr << name_program << " - empty executable path\n";
            name = "Empty name";
        }
        if (name.empty())
            name = FSUtils::GetFileNameWithoutExtension(path_executable);
        return name;
    }
    const string &getDescription()
    {

        if (path_description.empty()) // Error handling:
        {
            cerr << name_program << " - empty description path\n";
            description = "Empty description";
        }
        if (description.empty())
        {
            ifstream file(path_description, std::ios::end);
            int size = file.tellg();
            if (size == -1) // Error handling:
            {
                description = "Empty description";
                cerr << name_program << " - empty description file\n";
            }
            description.resize(size);
            file.seekg(0);
            file.read(&description[0], size);
        }
        return description;
    }

private:
    string name, description;
};

class ExecManager
{
private:
    fs::path path_executables;
    fs::path self_path;
    map<string, Exec> paths;

public:
    ExecManager(fs::path path)
    {
        if (path.is_relative())
            path = fs::absolute(path).lexically_normal();
        self_path = path;
        path_executables = path.parent_path().parent_path().parent_path();
    }

    // Found executables in programs' build directory
    void find()
    {
        string current_program;
        for (fs::recursive_directory_iterator iterator(path_executables); iterator != fs::recursive_directory_iterator(); iterator++)
        {
            auto &path = iterator->path();

            if (iterator.depth() == 0 && iterator->is_directory()) // Get name directory on depth 0 and assign to current_program and insert to paths with empty Exec
            {
                current_program = path.filename();
                paths.insert(pair<string, Exec>(current_program, Exec(current_program)));
            }

            if (path.extension() == ".exec" /* && path.compare(self_path) != 0 */) // Assign program's path executable to Exec of current_program
                paths.at(current_program).path_executable = path;
            else if (path.filename() == "Description") // Assign program's path Description to Exec of current_program
                paths.at(current_program).path_description = path;

            if (iterator.depth() >= 2 || (iterator.depth() == 1 && (iterator->is_directory() && path.filename() != "build"))) // Stop recursion if depth greater than 2 or next directory not "build"
                iterator.disable_recursion_pending();
        }
    }

    // Print description by executing program with argument
    void printExecInfo()
    {
        int index;
        for (auto &path : paths)
        {
            cout << index << ". " << path.second.getName() << " - " << path.second.getDescription() << '\n';
            index++;
        }
    }

    void choose()
    {
    }
};

int main(int argc, char **argv)
{
    ExecManager man(argv[0]);
    man.find();
    man.printExecInfo();
    return 0;
}
