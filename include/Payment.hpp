#ifndef PAYMENT_H
#define PAYMENT_H

#include<string>

enum class PaymentMethod {
   CreditCard,
   UPI,
   DebitCard,
   Cash
};

class Payment {

private: 
   int PaymentId;
   PaymentMethod Method;
   int PaymentAmount;

public:
   Payment(PaymentMethod Method,int Paymentamount);
   void PaymentSuccessful();

};

#endif