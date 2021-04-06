#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Con el modulo de vectores directamente podría haber hecho las actividades pero como el libro lo explica mediante arrays lo convierto todo a ellas.
// Podria hacerlo directamente con arrays pero queria implementar de forma dinamica el tema de preguntar los numeros al usuario, y podria haberlo hecho
// con arrays directamente, pero las arrays no permiten un tamaño por parametro cuando las hacemos static asi que he utilizado los vectores. Igualmente
// la resolucion de las actividades estan planteadas con arrays por lo que no hay problema.

vector<float> askNumbers(int size, int exercise){
    static vector<float>values;
    float value;
    values.clear();
    for (int i = 0; i < size; i++)
    {
        if (exercise == 3){
            cout << "Teniendo en cuenta que '1' es enero y '12' es diciembre, introduce un numero de mes: "; cin >> value;
            values.push_back(value);
            cout << "Introduce un dia: "; cin >> value;
            values.push_back(value);
        }
        else if (exercise == 5 || exercise == 7)
        {
            cout << "Introduce una coordenada x para el " << i+1 << " vector: "; cin >> value;
            values.push_back(value);
            cout << "Introduce una coordenada y para el " << i+1 << " vector: "; cin >> value;
            values.push_back(value);
        }
        else if (exercise == 6)
        {
            cout << "Introduce una coordenada x para el " << i+1 << " vector: "; cin >> value;
            values.push_back(value);
            cout << "Introduce una coordenada y para el " << i+1 << " vector: "; cin >> value;
            values.push_back(value);
            cout << "Introduce una coordenada z para el " << i+1 << " vector: "; cin >> value;
            values.push_back(value);
        }
        else if (exercise == 8)
        {
            cout << "Introduce, respectivamente, los valores de la fila numero " << i+1 << ": "; cin >> value;
            values.push_back(value);
            cout << "Introduce, respectivamente, los valores de la fila numero " << i+1 << ": "; cin >> value;
            values.push_back(value);

        }
        else if (exercise == 9)
        {
            cout << "Introduce, respectivamente, los valores de la fila numero " << i+1 << ": "; cin >> value;
            values.push_back(value);
            cout << "Introduce, respectivamente, los valores de la fila numero " << i+1 << ": "; cin >> value;
            values.push_back(value);
            cout << "Introduce, respectivamente, los valores de la fila numero " << i+1 << ": "; cin >> value;
            values.push_back(value);
        }
        
        else {
            cout << "Introduce un numero: "; cin >> value;
            values.push_back(value);
        }

    }
    return values;
}


// Ejercicio 1 pag 128
float arrays1(float num1, float num2, float num3 , float num4) {
    float total = 0;
    float result;
    float array[4] = {num1, num2, num3, num4};
    for (int i = 0; i < 4; i++)
    {
        float actual_number = array[i];
        total = actual_number + total;

    }
    result = total / 4;
    return result;
}

// Ejercicio 2 pag 128
int arrays2(int month) {
    int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return array[month];
}

// Ejercicio 3 pag 128
int arrays3(int month, int day) {
    int total;
    bool valid = false;
    int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (valid == false)
    {
        
        if (1 <= day && day <= array[month]) 
        {
            for (int i = 0; i <= month; i++)
            {
                if (i != month)
                {
                    total = total + array[i];
                }
                else {
                    total = total + day;
                }
            }
            valid = true;
        }
        else{
            cout << "Has introducido un dia que no tiene ese mes, introduce uno correcto: "; cin >> day;
        }   
    }
    return total - 1; 
}

// Ejercicio 4 pag 128
float arrays4(float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8, float num9, float num10) {
    float array[10] = {num1, num2, num3, num4, num5, num6, num7, num8, num9, num10};
    int max_number = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] > max_number) {
            max_number = array[i];
        }
    }
    return max_number;
}

// Ejercicio 5 pag 128
void arrays5(int num1, int num2, int num3, int num4, float& x_value, float& y_value) {
    int vector1[2] = {num1, num2};
    int vector2[2] = {num3, num4};
    int final_vector[2];
    for (int i = 0; i < 2; i++)
    {
        final_vector[i] = vector2[i] - vector1[i];
    }
    x_value = final_vector[0];
    y_value = final_vector[1];
}

// Ejercicio 6 pag 128
float arrays6(float num1, float num2, float num3, float num4, float num5, float num6){
    float vector1[3] = {num1, num2, num3};
    float vector2[3] = {num4, num5, num6};
    float final_vector;
    for (int i = 0; i < 3; i++)
    {
        final_vector += vector1[i] * vector2[i];
    }
    return final_vector;
    
}

// Ejercicio 7 pag 128
void arrays7(float num1, float num2, float num3, float num4) {
    float vector1[2] = {num1, num2};
    float vector2[2] = {num3, num4};
    if ((vector2[0]/vector1[0]) == (vector2[1]/vector1[1]))
    {
        cout << "Los vectores son linealmente dependientes";
    }
    else{
        cout << "Los vectores no son linealmente dependientes";
    }
}

// Ejercicio 8 pag 128
void arrays8(float num1, float num2, float num3, float num4){
    float matrix[2][2] = {{num1, num2}, {num3, num4}};
    float transpose_matrix[2][2] = {{matrix[0][0], matrix[1][0]}, {matrix[0][1], matrix[1][1]}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
        cout << transpose_matrix[i][j];
        }
        cout << endl;
    }
}

// Ejercicio 9 pag 128
float arrays9(float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8, float num9){
    float det;
    float matrix[3][3] = {{num1, num2, num3}, {num4,num5,num6}, {num7,num8,num9}};
    det = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[1][0] * matrix[2][1] * matrix[0][2])-( (matrix[0][2] * matrix[1][1] * matrix[2][0]) + (matrix[0][1] * matrix[1][0] * matrix[2][2]) + (matrix[1][2] * matrix[2][1] * matrix[0][0]) );
    return det;
}

// Ejercicio 10 pag 128
void arrays10(float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8, float num9, float num10){
    float array[10] = {num1, num2, num3, num4, num5, num6, num7, num8, num9, num10};
    int i, j;
    float result;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (array[j] > array[j+1])
            {
                result = array[j];
                array[j] = array[j+1];
                array[j+1] = result;
            }
        }
    }
    cout << "En orden de menor a mayor, los numeros quedarian ordenados de la siguiente forma: (";
    for (i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            cout << array[i];
        }
        else{
            cout << array[i] << ",";
        }
    }
    cout << ")";
}

// Ejercicio 1 pag 132
void files1() {
    int num=1;
    ofstream file("numeros.txt");
    while (num!=0){
        cout <<"Escribe un numero(cero cerrara el programa): ";
        cin >>num;
        file << num << endl;
    }
    file.close();
    cout << "EL fichero ha sido creado" << endl;
}

// Ejercicio 2 pag 132
void files2() {
    string name;
    string line;
    cout << "Introduce el nombre del fichero que quieres leer(he adjuntado un texto de prueba llamado 'text.txt' para probarlo): "; cin >> name;
    fstream file(name.c_str());
    if (file.fail())
    {
        cout << "El nombre de archivo que has introducido no existe, por lo que el ejercicio ha finalizado";
        return ; 
    }
    while(getline(file,line))
    {
        if (! file.eof())
        {
            for (int i = 0; i < 24; i++)
            {
		        getline(file,line);
                cout << endl << i+1 << ") " << line << endl;
            }
            cout << "\n(pausa)\n";
        }  
      }
    file.close();
}

// Ejercicio 3 pag 132
int files3() {
    string line;
    int total = 0;
    ifstream file("numeros.txt");
    while (getline(file, line))
    {
        total += stoi(line);
    }
    file.close();
    return total;
}

// Ejercicio 4 pag 132
char files4() {
    string name;
    cout << "Introduce el nombre del fichero del que quieres ver su ultimo byte(puedes probarlo con 'numeros.txt'): "; cin >> name;
    ifstream file(name.c_str(), ifstream::binary);
    if (file.fail())
    {
        cout << "El nombre de archivo que has introducido no existe, por lo que el programa ha finalizado.";
        exit(1);
    }
    file.seekg(-1, file.end); //Posicionamos el curso al final usando -1
    char byte = file.get();
    return byte;
}

//Ejercicio 5 pag 132
int files5(){
    string name;
    char byte, c;
    int count = 0;
    cout << "Introduce el nombre del fichero(puedes probarlo con 'numeros.txt'): "; cin >> name;
    ifstream file(name.c_str(), ifstream::binary);
    if (file.fail())
    {
        cout << "El nombre de archivo que has introducido no existe, por lo que el programa ha finalizado.";
        exit(1);
    }
    cout << "Introduce el byte que quieres comprobar cuantas veces se repite: "; cin >> byte;
    while (!file.eof())
    {
        c = file.get();
        if (c == byte)
            count++;
    }
    return count;
}

//Ejercicio 1 pag 135
void saludarVariasVeces(int value) {
    for (int i = 0; i < value; i++)
    {
        cout << "Hola " << endl;
    }
    
}

// Ejercicio 2 pag 135
void escribirTabla(int num) {
    for (int i = 1; i < 11; i++)
    {
        cout << num << "x" << i << " es: "<< num*i << endl;
    }
    
}

//Ejercicio 1 pag 136
float suma(float num1, float num2, float num3){
    return num1+num2+num3;
}

//Ejercicio 2 pag 136
int esPrimo(int num1){
    int contador=0;
    for(int i=1; i<=num1; i++) //Compruebo cuantas veces su resto es cero, si es igual a dos es primo
    {
        if(num1%i==0) 
        {
            contador++; 
        }
    }
    if(contador==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Ejercicio 1 pag 137
void intercambia(int &a, int &b){
    cout << "La variable 'a' antes de ser intercambiada vale: " << a << " y la variable 'b': " << b << endl;
    int e = a;
    a = b;
    b = e;
    cout << "Ahora 'a' vale: " << a << " y 'b' vale: " << b;
}

// Ejercicio 13 pag 139
void user_register(){
    string line;
    string text;
    bool valid = true;
    fstream file("registroDeUsuario.txt",ios::out);
    while (valid == true){
        cout <<"Escribe texto(Fin/fin dejara de hacerlo): ";  
        getline(cin, text);
        if (text == "Fin" || text == "fin")
        {
            valid = false;
        }
        else{
            file << text << endl;
        }
    }
    file.close();
    file.open("registroDeUsuario.txt");
    cout << endl << "El archivo contiene los siguientes datos: " << endl;
    while (getline (file, line))
    {
        cout << line << endl;
    }
    file.close();
}

//Ejercicio 18 pag 129
void number_guessing(int num1) {
    int count = 1;
    int attempts = 10;
    int random;
    if (num1 >= 1 && num1<=1000)
    {
        while(count < 10){
            srand (time(NULL)); //inicializamos los numeros aleatorios 
            random = (rand() % 1001);
            if(num1 < random){
                cout<<"Te has quedado corto, introduce otro numero(intentos restantes:"<<attempts-1<<"): "; cin>>num1;
                count++;
                attempts = attempts - 1;
            }
            else if (num1 > random)
            {
                cout<<"Te has pasado de grande, introduce otro numero(intentos restantes:"<<attempts-1<<"): "; cin>>num1;
                count++;
                attempts = attempts - 1;
            }
            else
            {
                cout<<"Has acertado!";
            }
            
        }
        cout << "No has conseguido averiguar el numero, el numero era: "<< random;
    }
}

int main(){
    int option_type, option_arrays, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, result, option_files, option_functions;
    char byte;
    while (true)
    {
        system("cls");
        cout << R"(
 __       __                               
|  \     /  \                              
| $$\   /  $$  ______   _______   __    __ 
| $$$\ /  $$$ /      \ |       \ |  \  |  \
| $$$$\  $$$$|  $$$$$$\| $$$$$$$\| $$  | $$
| $$\$$ $$ $$| $$    $$| $$  | $$| $$  | $$
| $$ \$$$| $$| $$$$$$$$| $$  | $$| $$__/ $$
| $$  \$ | $$ \$$     \| $$  | $$ \$$    $$
 \$$      \$$  \$$$$$$$ \$$   \$$  \$$$$$$                                      
)"<< endl << endl;
        cout << "A que campo de ejercicios quieres acceder?\n1)Arrays\n2)Ficheros\n3)Funciones\n--> "; cin >> option_type;
        switch (option_type)
        {
        case 1:
            system("cls");
            cout << R"( 
    ______                                                   
    /      \                                                  
    |  $$$$$$\  ______    ______   ______   __    __   _______ 
    | $$__| $$ /      \  /      \ |      \ |  \  |  \ /       \
    | $$    $$|  $$$$$$\|  $$$$$$\ \$$$$$$\| $$  | $$|  $$$$$$$
    | $$$$$$$$| $$   \$$| $$   \$$/      $$| $$  | $$ \$$    \ 
    | $$  | $$| $$      | $$     |  $$$$$$$| $$__/ $$ _\$$$$$$\
    | $$  | $$| $$      | $$      \$$    $$ \$$    $$|       $$
    \$$   \$$ \$$       \$$       \$$$$$$$ _\$$$$$$$ \$$$$$$$ 
                                        |  \__| $$          
                                            \$$    $$          
                                            \$$$$$$           )" << endl << endl;
            
            cout << "Selecciona el número del ejercicio(1-10):\n--> "; cin >> option_arrays;
            {     
                if (option_arrays == 1)
                {
                    vector<float>numbers = askNumbers(4,1);
                    cout << "La media aritmetica de: ("<< numbers[0] << ", "<<  numbers[1] << ", " << numbers[2] << ", " << numbers[3] << ") es: " << arrays1(numbers[0], numbers[1], numbers[2], numbers[3]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }
                
                else if (option_arrays == 2)
                {
                    cout << "Teniendo en cuenta que '1' es enero y '12' es diciembre, ";
                    vector<float>numbers = askNumbers(1,2);
                    cout << "El mes seleccionado tiene " << arrays2(numbers[0]-1) << " dias";
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }

                else if (option_arrays == 3)
                {
                    vector<float>numbers = askNumbers(1,3);
                    cout << "En el calendario, el dia del mes seleccionado es el dia numero " << arrays3(numbers[0] - 1, numbers[1]) << " de 365 dias que tiene el año (no bisiesto).";
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }

                else if (option_arrays == 4) 
                {
                    vector<float>numbers = askNumbers(10,4);
                    result = arrays4(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                    cout << "El mayor de los numeros introducidos en la array es: " << result;
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }

                else if (option_arrays == 5)
                {
                    vector<float>numbers = askNumbers(2,5);
                    float x_value, y_value;
                    arrays5(numbers[0], numbers[1], numbers[2], numbers[3], x_value, y_value);
                    cout << "El vector diferencia es: (" << x_value << "," << y_value << ")";
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }

                else if (option_arrays == 6)
                {
                    vector<float>numbers = askNumbers(2,6);
                    cout << "El producto escalar de los dos vectores introducidos es: " << arrays6(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }
                else if (option_arrays == 7)
                {
                    vector<float>numbers = askNumbers(2,7);
                    arrays7(numbers[0], numbers[1], numbers[2], numbers[3]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }
                else if (option_arrays == 8)
                {
                    vector<float>numbers = askNumbers(2,8);
                    arrays8(numbers[0], numbers[1], numbers[2], numbers[3]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }
                else if (option_arrays == 9)
                {
                    vector<float>numbers = askNumbers(3,9);
                    cout << "El determinante de la matriz es: " << arrays9(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                }
                else if (option_arrays == 10) {
                    vector<float>numbers = askNumbers(10,10);
                    arrays10(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                    cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                    getch();
                    

                } 
                else {
                    cout << "Introduce una opcion correcta(1-10): "; cin >> option_arrays;
                }
            }
            break;
        case 2:
            system("cls");
            cout << R"(
    ________  __            __                                               
    |        \|  \          |  \                                              
    | $$$$$$$$ \$$  _______ | $$____    ______    ______    ______    _______ 
    | $$__    |  \ /       \| $$    \  /      \  /      \  /      \  /       \
    | $$  \   | $$|  $$$$$$$| $$$$$$$\|  $$$$$$\|  $$$$$$\|  $$$$$$\|  $$$$$$$
    | $$$$$   | $$| $$      | $$  | $$| $$    $$| $$   \$$| $$  | $$ \$$    \ 
    | $$      | $$| $$_____ | $$  | $$| $$$$$$$$| $$      | $$__/ $$ _\$$$$$$\
    | $$      | $$ \$$     \| $$  | $$ \$$     \| $$       \$$    $$|       $$
    \$$       \$$  \$$$$$$$ \$$   \$$  \$$$$$$$ \$$        \$$$$$$  \$$$$$$$ 
                                                                                                                                                                                
    )" << endl << endl;     
             
            cout << "Selecciona el número del ejercicio(1-5):\n--> "; cin >> option_files;
            if (option_files == 1)
            {
                files1();
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }   
            if (option_files == 2)
            {
                files2();
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_files == 3)
            {
                cout << "La suma total de los numeros del archivo es: " << files3();
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_files == 4)
            {
                byte = files4();
                cout << "El ultimo byte del archivo indicado es: " << byte;
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_files == 5)
            {
                result = files5();
                cout << "El byte indicado del archivo dado se repite: " << result << " veces";
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            break;
        case 3:
            system("cls");
            cout << R"(
    ________                               __                                         
    |        \                             |  \                                        
    | $$$$$$$$__    __  _______    _______  \$$  ______   _______    ______    _______ 
    | $$__   |  \  |  \|       \  /       \|  \ /      \ |       \  /      \  /       \
    | $$  \  | $$  | $$| $$$$$$$\|  $$$$$$$| $$|  $$$$$$\| $$$$$$$\|  $$$$$$\|  $$$$$$$
    | $$$$$  | $$  | $$| $$  | $$| $$      | $$| $$  | $$| $$  | $$| $$    $$ \$$    \ 
    | $$     | $$__/ $$| $$  | $$| $$_____ | $$| $$__/ $$| $$  | $$| $$$$$$$$ _\$$$$$$\
    | $$      \$$    $$| $$  | $$ \$$     \| $$ \$$    $$| $$  | $$ \$$     \|       $$
    \$$       \$$$$$$  \$$   \$$  \$$$$$$$ \$$  \$$$$$$  \$$   \$$  \$$$$$$$ \$$$$$$$                                                                                                 
    )" << endl << endl;       
            
            cout << "Selecciona el número del ejercicio(1-7, respectivamente al orden de ejercicios indicados en classroom):\n--> "; cin >> option_functions;
            if (option_functions == 1)
            {
                cout << "Indica el numero de veces que quieres que el programa te salude: "; cin >> num1;
                saludarVariasVeces(num1);
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 2)
            {
                cout << "Indique el numero del que quieres consultar su tabla de multiplicar: "; cin >> num1;
                escribirTabla(num1);
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 3)
            {
                vector<float>numbers = askNumbers(3,18); 
                cout << "La suma de los numeros introducidos es: " << suma(numbers[0], numbers[1], numbers[2]);
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 4)
            {
                vector<float>numbers = askNumbers(1,19); 
                cout << "El numero introducido es: ";
                if (esPrimo(numbers[0]) == 0)
                {
                    cout << "no primo";
                }
                else{
                    cout << "primo";
                }
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 5)  
            {
                vector<float>numbers = askNumbers(2,20); 
                num1 = numbers[0];
                num2 = numbers[1];
                intercambia(num1, num2);
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 6)
            {
                user_register();
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            if (option_functions == 7)
            {
                vector<float>numbers = askNumbers(1,22); 
                number_guessing(numbers[0]);
                cout << endl << "[Pulsa cualquier tecla para volver al menu]";
                getch();
            }
            break;
        }
    }
}