#include "Utils/Common.hpp"
#include "Utils/Unix.hpp"

struct Exec
{
    fs::path path_executable, path_description;
    string name_program;

    Exec(string name_program) : name_program(name_program) {}

    const string &getName()
    {
        if (path_executable.empty()) // Error handling: if empty assign and print error message
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

        if (path_description.empty()) // Error handling: if empty assign and print error message
        {
            cerr << name_program << " - empty description path\n";
            description = "Empty description";
        }
        if (description.empty())
        {
            ifstream file(path_description, std::ios::end);
            auto size = file.tellg();
            if (size == -1) // Error handling: if empty assign and print error message
            {
                description = "Empty description";
                cerr << name_program << " - empty description file\n";
            }
            else
            {
                description.resize(size);
                file.seekg(0);
                file.read(&description[0], size);
            }
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
    // map<string, Exec> paths;
    vector<Exec> paths;

public:
    ExecManager(fs::path path)
    {
        if (path.is_relative())
            path = fs::absolute(path).lexically_normal();
        self_path = path.parent_path().parent_path();
        path_executables = path.parent_path().parent_path().parent_path();
    }

    void find() // Found executables in programs' build directory
    {
        for (fs::recursive_directory_iterator iterator(path_executables); iterator != fs::recursive_directory_iterator(); iterator++)
        {
            auto &path = iterator->path();

            if (iterator->path().compare(self_path) == 0) // Skip if it self_path
            {
                iterator.disable_recursion_pending();
                continue;
            }

            if (iterator.depth() == 0 && iterator->is_directory()) // Initialise current path in paths
                paths.push_back(Exec(path.filename()));

            if (path.extension() == ".exec") // Assign program's path executable to Exec of last element of paths
                paths.back().path_executable = path;
            else if (path.filename() == "Description") // Assign program's path Description to Exec of last element of paths
                paths.back().path_description = path;
            if (iterator.depth() >= 2 || (iterator.depth() == 1 && (iterator->is_directory() && path.filename() != "build"))) // Stop recursion if depth greater than 2 or next directory not "build"
                iterator.disable_recursion_pending();
        }
    }

    void printExecInfo() // Print description of Exec files and order in
    {

        cout << "0. Exit\n";
        for (auto path : paths)
        {
            static short index{1};
            cout << index++ << ". " << path.getName() << "  -  " << path.getDescription() << '\n';
        }
    }

    void choose()
    {

        cin.exceptions(std::ios::failbit);
        while (true)
        {
            try
            {
                size_t index;
                cin >> index;
                if (index == 0)
                    break;
                auto path = paths.at(index - 1 /* index 0 is exit */).path_executable.c_str();
                execl(path, path);
            }
            catch (std::ios::failure)
            {
                cout << "You can enter only numbers(0-9)" << endl;
            }
            catch (out_of_range)
            {
                cout << "You enter wrong number of command" << endl;
            }
        }
    }
};

int main(int argc, char **argv)
{
    ExecManager man(argv[0]);
    man.find();
    man.printExecInfo();
    man.choose();
    return 0;
}
