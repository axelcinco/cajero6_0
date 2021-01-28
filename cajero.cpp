#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include<direct.h>
#include<stdio.h>
#include<windows.h>

using namespace std;
string usuario="",nip="";
int respuesta=0, contador=0,opc=0,opc2=0;
int monto=0,transf=0,pag_agua=0,pag_agua2=0,pag_agua3=0,pag_luz=0,pag_luz2=0,pag_luz3=0;
int  monto_2=0,retiro1=0;
string auxiliar_usua,auxiliar_nip,num_transfe,aux_usuario;
double saldo_inicial=0;
double servicios=0;
string nombre_archivo;
fstream archivo;
string archivos2;
char fecha[25];
time_t current_time;


bool busqueda=false;  //archivos para poder crear los archivos o manipularlos
int x=0,y=0;




void gotoxy(int x,int y)
{

    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);	
}

 void  registros()
 {
  
    archivo.open(archivos2.c_str(),ios::app);
    
    switch(opc)
    {
    	case 1:
    		archivo<<" se hizo un deposito de " <<monto<<" y su fecha fue "<<fecha<<endl;
    		break;
    	case 2: 
    	  	archivo<<" se hizo un retiro de " <<monto_2<<" y su fecha fue "<<fecha<<endl;
    	break;
    	case 4:
    	     archivo<<" el monto transferido fue  " <<monto<<" del usuario "<< usuario<<" al usuario "<<aux_usuario<<" en la fecha "<<fecha;
    	    
    		break;
    	case 5:
    		switch(opc2)
    		{
    			case 1:
    				archivo<<" el pago ala comision de agua fue de "<<servicios<< " en la fecha "<<fecha;
    			case 2:
    			 	archivo<<" el pago ala comision de luz fue de "<<servicios<< " en la fecha "<<fecha;
    			break;
			}
    		break;
    	
    	 
    		
    	
	}
    
    archivo.close();
 }
void ver_registros()
{
	string aux_registros;
	
	archivo.open(archivos2.c_str());
	cout<<" ***movimientos realizados en el dia *** "<<endl;
	while(!archivo.eof())
	{
	
	   getline(archivo,aux_registros);
	   cout<<aux_registros<<endl;
	   	
	}
	archivo.close();
	
	
}

void crear_usuario()
{
	string cadena="1234567890";
	int i;
	string tarjeta;
	srand(time(NULL)); //esto sirve para que no se repite el mismo numero aleatorio

	for(i=0; i<10; i++)
	
	{
		                                           
         tarjeta+=cadena[rand()%(0-10)];              
         
	}
	
	cout<<" su numero de tarjeta es "<<tarjeta<<endl;
	
	
	do
	{
	  cout<<"digite el nip que deseado ";cin>>nip;	
		
	}while(nip.length()!=4);  //esta validacion es para que el usuario solo digite en su nip 4 numeros 
	
		archivo.open(tarjeta.c_str(),ios::app);
		archivo<<nip<<'\n';
		archivo<<0<<'\n';
		
		
		archivo.close();
	 
	
}



void decision()
{
	string respuesta;
	cout<<" quieres crear un usuario ???? ";cin>>respuesta;
    if(respuesta=="si")
    {
       crear_usuario();
	}
	else
	{
		return;
		
	}
	
}



  void buscar_nip()
  {
  	 busqueda=false;
  	 
  	 auxiliar_nip="";
  	 
  	 
  	
     archivo.open(usuario.c_str());
       archivo>>auxiliar_nip;
       
       if(nip==auxiliar_nip)
       {
       	  busqueda=true;
       	  archivo>>saldo_inicial;
       	  
       	
	   }
       
     
	 archivo.close();	
  }
 void guardar_datos()
 {
 	archivo.open(usuario.c_str());
 	archivo<<nip<<'\n';
 	archivo<<saldo_inicial<<'\n';
 	archivo.close();
 }
void leer_datos()
{
		archivo.open(usuario.c_str());
		archivo>>nip;
		archivo>>saldo_inicial;
		
		archivo.close();
}
double deposito(double monto)
   {
       saldo_inicial=saldo_inicial+monto;
       cout<<" deposito exitoso su saldo es: "<<saldo_inicial;
       
       
   
}

//funcion para el retiro

 double retiro(double monto_2)
 {
 	
 	 	if(saldo_inicial >= monto_2 && monto_2>0)
 		{
 			saldo_inicial = saldo_inicial - monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial;
 			cout<<endl;
 			
 			
	 }
 		
 	else{  
 				
 	     	cout<<"no tienes dinero en tu cuenta para retirar";
		}  
			 
	  	
	  
 	       			 

 	
 } //cierre de la funcion retiro
 
 
  void  cambio_nip()
  {
  	 
    string aux_nip;
  		
  		
  	 
  	 	cout<<"ingrese su nip: ";cin>>auxiliar_nip;
  	 	if(nip==auxiliar_nip)
  	 	{
  	 		do
  	 		{
	            cout<<"ingrese el  nuevo nip ";cin>>aux_nip;
	            
			  
			}while(aux_nip.length()!=4);
			
			nip=aux_nip;
			
	     }
  	 
	   
	   
	   
	   	guardar_datos();
  	 	
	 
  	 
  	 
  	
	   
	   
  }//cierre de la funcion   cambio nip
  
  void transfe()
  {
       string nip_aux2;
       double monto,monto_tra;
       
       cout<<" digite ala cuenta que quiere tarnsferir ";cin>>aux_usuario;
    if(aux_usuario==usuario)
    {
    	cout<<"no se puede transferir ala misma cuenta "<<endl;
    	
	}
	else
	{
		archivo.open(aux_usuario.c_str());
       if(archivo!=NULL)
       {
       	   cout<<"ingresa el monto que quieres tarnsferir ";cin>>monto;
       	   if(monto>0 && saldo_inicial>=monto )
       	   {
       	   	   archivo>>nip_aux2;
       	   	   archivo>>monto_tra;
       	   	   archivo.close();
       	   	    archivo.open(aux_usuario.c_str());
       	   	   saldo_inicial=saldo_inicial-monto;
       	   	   monto_tra+=monto;
       	   	   archivo<<nip_aux2<<'\n';
       	   	   archivo<<monto_tra<<'\n';
       	   	  
       	   	    archivo.close();
  	 
       	   	   cout<<"transferencia exitosa el monto transferido es de: "<<monto;
       	   	   
       	   	   registros();
       	   	   
       	   	   
       	   	   
		   }
		   else
		   {
		   	  cout<<"no cuenta con suficiente saldo para transferir "<<endl;
		   }
		   
		
	   }
       else
       {
       	 cout<<"no se encontro el numero de tarjeta "<<endl;
	   }
	}
       
  		
 
  	
  }//cierre de la funcion transfe
 
 
 
    void consulta()
    {
    	 
    	
		   cout<<" su saldo actual es: "<<saldo_inicial;
		   cout<<endl;	
    		
	
    	
    	
    	
	}//cierre de la funcion consulta de saldo
	
	double pagos()
	{
		cout<<" digite el monto que va pagar ";cin>>servicios;
		if((saldo_inicial>=servicios && servicios>0)) 
		{
				cout<<" digite 1.- si su pago para la comision de agua "<<'\n';
			cout<<" digite 2.- si su pago es para a comision de luz "<<'\n';
			cout<<" digite la opcion que desea ";cin>>opc2;
				switch(opc2)
				{
					case 1:
						  
						 	saldo_inicial=saldo_inicial-servicios;
						 	pag_agua+=servicios;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   
						  
					 
						   
						   break;//fin del caso 1
					case 2:  
					   	
						 	saldo_inicial=saldo_inicial-servicios;
						 	pag_luz+=servicios;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   
						  
						  
					break;
					registros();
			}
		}
		else
		{
		  cout<<"no tiene suficiente dinero para transferir o digite numeros mayores que cero "<<'\n';
			
		}
		
		
		
	}//cierre de la funcion pagos 
 
 //comienzo del int main 

int main() {

 system ("cls");

	
while(contador!=3)
{
	 	
	  	decision(); //le mando a hablar ala funcion  decision para crear un usuario nuevo
	  	system ("cls");
		cout<<" \n ingrese el nombre del usuario: "; cin>>usuario;
		cout<<" \n ingrese el password del usuario: "; cin>>nip;
		 buscar_nip();
		if(busqueda==true)
		{
			
	   system("cls");		
	do{
	  current_time=time(NULL);
    ctime(&current_time);
    strcpy(fecha, ctime(&current_time));
   
     archivos2="registros/"+usuario+".txt";
		 contador=0;
		 leer_datos();
			gotoxy(80,1);	cout<<" fecha y hora: "<< fecha;
			cout<<" bienvenido al banco garcia";
			cout<<endl;
		cout<<"****************************************"<<endl;
				
		       cout<<" saldo inicial: "<<saldo_inicial;
		       cout<<endl;
			

		
			cout<<"_______________________________";
			cout<<endl;
			cout<<"presione 1.- para deposito"<<'\n';           //hacemos un menu para el usuario
			cout<<"presione 2.- para retiro"<<'\n';
			cout<<"presion 3.- para cambiar nip"<<'\n';
			cout<<"presione 4.- para hacer transacciones"<<'\n';
			cout<<"presione 5.- para consultar su saldo"<<'\n';
			cout<<"presione 6.- para hacer pagos de luz y agua  "<<'\n';
			cout<<"presione  7.- para ver las transferencias que sean realizado en el dia "<<'\n';
			cout<<"presione 8.- para cambiar de usuario "<<'\n';
			
			cout<<"____________________________________"<<'\n';
			 string nip_aux="";
			cout<<"elija una opcion: ";cin>>opc; //leemos la opcion para el menu
			system("cls");
			switch(opc)
			
			{
				  
				case 1:
					
					  cout<<" deposito de dinero: "<<endl;
					  cout<<"ingrese el monto que quiere depositar: "; 
					  cin>>monto;
                      cout<<endl; 
                      if(monto>0)
                      {
                      	 if(monto % 20==0 || monto % 50==0)
                      	 {
                      	 deposito(monto);  
                      	  guardar_datos();
                      	   registros();
						   }
						else
						{
							cout<<"no se puede depositar esa cantidad "<<endl;
						}
                      	 
					  }
					  else
					  {
					  	cout<<" el monto debe ser mayor que cero";
					  }
					 
					
				break;
				
					
				case 2:
				
					cout<<" retiro bancarias"<<endl;
					cout<<"ingrese el monto que quiere retirar: "; 
					  cin>>monto_2;
					  if(monto_2>0)
					  {
					  	 if(monto_2 % 20==0 || monto_2 % 50==0)
					  	 {
					  	   retiro(monto_2);	
					   	  guardar_datos();
					   	    registros();
						   }
					   else
					   {
					   	  cout<<"no se puede retirar esa cantidad "<<endl;
					   }
					  }
					  else
					  {
					  	cout<<"el monto tiene que ser mayor a 0";
					  }
				
					
				break;
					
				case 3:
					
					cout<<"cambio de nip:"<<endl;
					 cambio_nip();
				
					 
					break;
					case 4:

						 	 
						     transfe();
						 	guardar_datos();
						
						 break;
						 
					case 5:
					
						cout<<"consulta de saldo: "<<endl;
						   consulta();
	
						   guardar_datos();
						break;
						case 6:
							pagos();
							guardar_datos();
								
						break;
						
						case 7:
							 ver_registros();
							break;
					
				   case 8:
				    break;
					break;
					
				default:
					cout<<"opcion invalida"<<endl;
					
				break;
						
				
			}   //termina el switch
			cout<<endl;	
			system("pause");
			system("cls");
			
				
}while(opc!=8); // termino del ciclo while condicion para que cuando el usuario de mas de 3 intentos se cierre el programa	}while(respuesta!=2);	

}
	else 
			{
				 
				 contador=contador+1;
				 	cout<<"  datos erroneos: "<<endl;
				 	cout<<" ADVERTENCIA, tienes tan solo 3 intentento y llevas "<<contador; 
				 	cout<<endl;
					
}		
		}
    

	return 0;
}
