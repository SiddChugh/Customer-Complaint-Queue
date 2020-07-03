// Description: Implementation of a customer complaint ticket class
#include "ticket.h"

Ticket::Ticket()
{
  ticketid = 0;
  customername = "";
  complaint = "";
}

Ticket::Ticket(unsigned int tid, std::string cname, std::string cplnt)
{
  ticketid = tid;
  if (cname == "")
    throw std::invalid_argument("Empty Customer Name");
  else
    customername = cname;
  if (cplnt == "")
    throw std::invalid_argument("Empty Complaint");
  else
    complaint = cplnt;
}

unsigned int Ticket::GetID() const
{
  return ticketid;
}

std::string Ticket::GetCustomer() const
{
  return customername;
}

std::string Ticket::GetComplaint() const
{
  return complaint;
}

bool Ticket::operator==(const Ticket& tick) const
{
  if (ticketid == tick.ticketid || 
     (customername == tick.customername && complaint == tick.complaint))
    return true;
  else
    return false;
}

bool Ticket::operator!=(const Ticket& tick) const
{
  return ! (*this == tick);
}