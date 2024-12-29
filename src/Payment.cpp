#include "../include/Payment.hpp"
#include<iostream>

int uniquePaymentId = 1;

Payment::Payment(PaymentMethod Method,int PaymentAmount) : Method(Method), PaymentAmount(PaymentAmount), PaymentId(uniquePaymentId++) {}

void Payment::PaymentSuccessful() {
   std::cout << "Payment Successful";
   std::cout << std::endl;
}

