#pragma once
struct positionObject
{
    int y, x;
};
struct entityObject
{
    shared_ptr<positionObject> pos;
    char character;
    typeObject type_object;
};