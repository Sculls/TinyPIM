#ifndef TINYPIM_ADDRESSBOOK_H
#define TINYPIM_ADDRESSBOOK_H

#include <vector>
#include "Address.h"

class AddressBook
{
    AddressBook();
    ~AddressBook();

    class AddressNotFound {};
    class DuplicateId {};

    int insertAddress(const Address& addr, int recordId = 0) throw (DuplicateId);
    void eraseAddress(int recordId) throw (AddressNotFound);
    void replaceAddress(const Address& addr, int recordId = 0) throw (AddressNotFound);
    const Address& getAddress(int recordId) const throw (AddressNotFound);

    void print() const;

private:
    // Disable copying
    AddressBook(const AddressBook&);
    AddressBook& operator=(const AddressBook&);

    static int nextId_;
    std::vector<Address> addresses_;

    int getById(int recordId) const;
    enum{notFound = -1};
};


#endif
