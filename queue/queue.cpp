// Developer - m1rskiy
// Date: 06.05.2024
#include <iostream>
#include <string>

#define N 10

using namespace std;

struct Ticket 
{
    int number;
    string owner;
    string time;
};

typedef struct Queue 
{
    int head;
    int tail;
    int size;
    struct Ticket list[N];
} queue_t;

void initialize(queue_t* q) 
{
    q->head = -1;
    q->tail = -1;
    q->size = 0;
}

void printLine()
{
    cout << "=================================" << endl;
}

void showMenu() 
{
    printLine();
    cout << "Welcome!" << endl;
    cout << "Choose what you want to do:" << endl;
    cout << "1. Add a ticket" << endl;
    cout << "2. Remove a ticket" << endl;
    cout << "3. Show all tickets" << endl;
    cout << "4. Exit" << endl;
    printLine();
}

void addTicket(queue_t* q) 
{
    if (q->size == N) 
    {
        cout << "The ticket queue is full." << endl;
        return;
    }

    Ticket newTicket;
    cout << "Enter ticket number: ";
    cin >> newTicket.number;
    cout << "Enter owner's name: ";
    cin >> newTicket.owner;
    cout << "Enter the time: ";
    cin >> newTicket.time;

    if (q->head == -1) 
    {
        q->head = 0;
    }
    
    q->tail = (q->tail + 1) % N;
    q->list[q->tail] = newTicket;
    q->size++;

    cout << "Ticket added successfully." << endl;
}

void removeTicket(queue_t* q) 
{
    if (q->size == 0) 
    {
        cout << "The ticket queue is empty." << endl;
        return;
    }

    cout << "Ticket removed: " << endl;
    cout << "Number: " << q->list[q->head].number << endl;
    cout << "Owner: " << q->list[q->head].owner << endl;
    cout << "Time: " << q->list[q->head].time << endl;

    q->head = (q->head + 1) % N;
    q->size--;
}

void showQueue(queue_t* q) 
{
    if (q->size == 0) 
    {
        cout << "The ticket queue is empty." << endl;
        return;
    }

    cout << "Ticket queue:" << endl;
    int i = q->head;
    for (int count = 0; count < q->size; ++count) 
    {
        cout << "Number: " << q->list[i].number << ", Owner: " << q->list[i].owner << ", Time: " << q->list[i].time << endl;
        i = (i + 1) % N;
    }
}

int main() 
{
    queue_t q;
    initialize(&q);

    int choice = 0;
    while (choice != 4) 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addTicket(&q);
                break;
            case 2:
                removeTicket(&q);
                break;
            case 3:
                showQueue(&q);
                break;
            case 4:
                printLine();
                cout << "Goodbye!" << endl;
                printLine();
                break;
            default:
                printLine();
                cout << "Invalid choice." << endl;
                printLine();
        }
    }

    return 0;
}
