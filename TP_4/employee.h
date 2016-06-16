
struct
{
    int id;
    int dni;
    char name[51];
    char lastName[51];
    char sector[51];
    int isEmpty;

}typedef Employee;

char menu(char textoMenu[],int min,int max);

Employee* newEmployee(int id, int dni, char name[],char lastName[],char sector[]);

int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee);

int obtenerId(void*empleado);

int compareEmployee(void* pEmployeeA,void* pEmployeeB);

void printEmployee(Employee* p);

void printArrayListEmployee(ArrayList* lista);

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int compararDni(ArrayList*pArrayEmpleado,int pElement);

void buscarDni(ArrayList*pArrayEmployee);

int compararId(ArrayList*pArrayEmpleado,int pElement);

int removeEmployee(ArrayList *pArrayEmployee);

void borrarLista(ArrayList*pArrayEmployee);

void imprimirId(ArrayList* pArrayEmployee);

int nuevoArchEmpleado(ArrayList *pArraylistEmployee);








