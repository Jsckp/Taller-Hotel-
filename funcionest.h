void ingresarClientes( char clientes[][2][40], int tamanoclien);
void buscarPorTamano(int *numHabitacion, char habitaciones[9][3][40], double precios[9]);
void buscarHotel(int *numHabitacion, char habitaciones[9][3][40], double precios[9]);
void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[][2][40], int reservas[10][4], int tamanoclien);
void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[10][4], int tamanoclien);
void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9], char clientes[][2][40], int tamanoclien);
void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9], char clientes[][2][40], int tamanoclien);
