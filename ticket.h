// Description: Definition of a customer complaint ticket class 

#ifndef _TICKET_H_
#define _TICKET_H_

#include <string>
#include <stdexcept>

class Ticket
{
private:
  unsigned int ticketid;
  std::string customername;
  std::string complaint;

public:
  // default constructor
  Ticket();

  // parameterized constructor
  Ticket(unsigned int tid, std::string cname, std::string comp);

  // MUTATORS

  // ACCESSORS
  unsigned int GetID() const;
  std::string GetCustomer() const;
  std::string GetComplaint() const;

 /**
   *overloaded operators
   *equality returns true if either ticketid matches,
   *or customername and complaint match
   */
  bool operator==(const Ticket& tick) const;
  bool operator!=(const Ticket& tick) const;
};

#endif