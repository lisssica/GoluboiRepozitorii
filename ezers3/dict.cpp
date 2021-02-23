#include <iostream>
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>

using namespace boost::multi_index;

class PhoneDictionary
{
public:
    struct Rec
    {
        std::string name;
        std::string phone;
        friend std::ostream &operator<<(std::ostream &o, const Rec &record)
        {
            return o << "name: " << record.name << "\tphone: " << record.phone;
        }
    };

    void insert(const Rec &record)
    {
        this->data.insert(record);
    }

    void printDict()
    {
        for (auto record : data.get<IndexType::ORDERED>())
        {
            std::cout << record << std::endl;
        }
    }

    const Rec &operator[](std::size_t idx) const { return this->data.get<IndexType::RANDOM_ACCESS>()[idx]; }

    Rec find(std::string name)
    {
        return *this->data.get<IndexType::HASHED>().find(name);
    }

private:
    enum IndexType
    {
        HASHED,
        ORDERED,
        RANDOM_ACCESS
    };

    multi_index_container<
        Rec, indexed_by<
                 hashed_non_unique<
                     member<Rec, std::string, &Rec::name>>,
                 ordered_non_unique<
                     member<Rec, std::string, &Rec::name>>,
                 random_access<>>>
        data;
};

int main(int argc, char **argv)
{
    PhoneDictionary store;
    //Inserting data
    store.insert({"cat", "011"});
    store.insert({"shark", "022"});
    store.insert({"dog", "033"});
    store.insert({"spider", "044"});

    //sorted
    std::cout << "Printing sorted list" << std::endl;
    store.printDict();
    std::cout << std::endl;

    //random access
    std::cout << "Printing random access" << std::endl;
    std::cout << store[0] << std::endl;
    std::cout << std::endl;

    //search
    std::cout << "Printing search" << std::endl;
    std::cout << store.find("cat") << std::endl;
    std::cout << std::endl;

       system("pause");

    return EXIT_SUCCESS;
}