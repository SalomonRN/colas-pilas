#include <iostream>
using namespace std;
struct NodeC
{
    int data;
    NodeC *next;
};
struct NodeP
{
    int data;
    NodeP *back;
};
NodeP *headP = NULL;
NodeC *headC = NULL;
void createC(NodeC *&head, int data)
{
    NodeC *new_node = new NodeC();
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        NodeC *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}
void createP(NodeP *&head, int data)
{
    NodeP *new_node = new NodeP();
    new_node->data = data;
    new_node->back = head;
    head = new_node;
}
void mostrarC(NodeC *&head)
{
    NodeC *current = head;
    if (head == NULL)
    {
        cout << "NADA QUE MOSTRAR" << endl;
        return;
    }
    do
    {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != nullptr);
    cout << "\n";
}
void mostrarP(NodeP *&head)
{
    NodeP *current = head;

    if (head == NULL)
    {
        cout << "NADA QUE MOSTRAR" << endl;
        return;
    }
    do
    {
        cout << current->data << endl;
        current = current->back;
    } while (current != nullptr);
    cout << "\n";
}
void atenderC(NodeC *&head)
{
    head = head->next;
}
void atenderP(NodeP *&head)
{

    head = head->back;
}
NodeC *cola(NodeC *head)
{
    int choise;
    int data;
    do
    {

        cout << "Opciones Cola:" << endl;
        cout << "1: Crear" << endl;
        cout << "2: Atender" << endl;
        cout << "3: Mostrar Cola" << endl;
        cout << "Opcion: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Valor a ingresar: " << endl;
            cin >> data;
            createC(head, data);
            break;
        case 2:
            atenderC(head);
            break;
        case 3:
            mostrarC(head);
            break;
        default:
            break;
        }
    } while (choise != 0);
    return head;
}
NodeP *pila(NodeP *head)
{
    int choise;
    int data;

    do
    {

        cout << "Opciones de Pila:" << endl;
        cout << "1: Crear" << endl;
        cout << "2: Atender" << endl;
        cout << "3: Mostrar Pila" << endl;
        cout << "Opcion: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Valor a ingresar: " << endl;
            cin >> data;
            createP(head, data);
            break;
        case 2:
            atenderP(head);
            break;
        case 3:
            mostrarP(head);
            break;
        default:
            break;
        }
    } while (choise != 0);
    return head;
}

int main()
{
    int choise;
    do
    {
        cout << "Opciones:" << endl;
        cout << "1: Pila" << endl;
        cout << "2: Cola" << endl;
        cin >> choise;
        if (choise == 1)
        {
            headP = pila(headP);
        }
        else
        {
            headC = cola(headC);
        }
    } while (choise != 0);
}
