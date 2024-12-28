#include "../include/Payment.hpp"
#include<iostream>

int uniqyeId = 1;

Payment::Payment(PaymentMethod Method,int PaymentAmount) : Method(Method), PaymentAmount(PaymentAmount), PaymentId(uniqyeId++) {}

void Payment::PaymentSuccessful() {
   std::cout << "Payment SuccessFul";
}

