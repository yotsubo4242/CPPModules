#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data("Hello, World!");
    std::cout << "Original data address: " << &data << std::endl;

    Serializer serializer;
    uintptr_t raw = serializer.serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserializedData = serializer.deserialize(raw);
    std::cout << "Deserialized value: " << deserializedData->getStr() << std::endl;

    deserializedData->setStr("Goodbye, World!");
    std::cout << "Modified deserialized value: " << deserializedData->getStr() << std::endl;

    std::cout << "Original data value: " << data.getStr() << std::endl;

    return 0;
}
