#include "TimeTable.h"

int main()
{
    
    // Зали
    // номер - редове - места (на ред)
    Hall h1 (8, 12, 7); 
    Hall h2(6, 11, 9);
    Hall h3(9, 10, 15);

    // Дати
    // ден - месец - година
    Date d1 (12, 7, 2022);
    Date d2(9, 3, 2022);
    Date d3(28, 2, 2022);
    //Date d4(30, 2, 2021);

    // Събития
    // дата - име - събитие
    Event ev1(d1, "Event1", h1);
    Event ev2(d2, "Event2", h2);
    Event ev3(d3, "Event3", h3);
    Event ev4(d2, "Event4", h1);

    // Списък от събития
    Event list[1] = { ev1 };

    // Разписания 
    // списък - дължина на списъка
    TimeTable t(list, 1);

    // Добавяне на събития
    t.addEvent(ev2);
    t.addEvent(ev3);
    t.addEvent(ev4);
    //t.printTimeTable();
    
    std::cout << "Free seats for Event 4:" << t.freeSeats(d2, "Event4") << std::endl;
    
    // Резервации (без заплащане) 
    // ред - място - парола за резервацията
    Reservation res1(2, 7, "1234");
    Reservation res2(5, 4, "7890");
    Reservation res3(6, 4, "8899");
   
    // Резервиране на места    
    t.saveTicket(d1, "Event1", res2); // в залата има 7 места на ред; 5-ти ред, 4-то място -> 32-ро място
    t.saveTicket(d1, "Event1", res1); // в залата има 7 места на ред; 2-ри ред, 7-мо място -> 14-то място
    t.saveTicket(d2, "Event2", res3); // в залата има 9 места на ред; 6-ти ред, 4-то място -> 49-то място
    
    // Премахване на резервация
    t.removeSavedTicket(d1, "Event1", res1);

    // Резервация на място, което ще се плати
    // ред - място
    Reservation res4(2, 7);

    // Купуване на билет
    // дата - име - резервация
    t.buyTicket(d1, "Event1", res4);
    t.buyTicket(d2, "Event4", res4);
    
    // Справка за резервиранитe, но неплатени места
    // дата - име ( "ALL" за всички дати или всички представления на конкретна дата)
    const char* fileName = "report-12.07.22-Event1.txt";
    t.reportReservedTickets(d1, "Event1" , fileName);
    
    Date firstDate = Date(2, 2, 2022);
    Date secondDate = Date(15, 7, 2022);
    t.reportPurchasedTickets(firstDate, secondDate, h2);
}