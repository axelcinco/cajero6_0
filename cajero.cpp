#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<ctime>

using namespace std;
string usuario="",nip="";
int respuesta=0, contador=0,opc=0;
double saldo_inicial=0,monto,transf=0,pag_agua=0,pag_agua2=0,pag_agua3=0,pag_luz=0,pag_luz2=0,pag_luz3=0;
double monto_2=0,retiro1=0;
string auxiliar_usua,auxiliar_nip,num_transfe;
string nombre_archivo;
fstream archivo;
bool busqueda=false;




void crear_usuario()
{
	string cadena="1234567890";
	int i;
	string tarjeta;
	srand(time(NULL));

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
       string aux_usuario,nip_aux2;
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
		cout<<" digite el monto que va pagar ";cin>>monto;
		if((saldo_inicial>=monto && monto>0)) 
		{
				cout<<" digite 1.- si su pago para la comision de agua "<<'\n';
			cout<<" digite 2.- si su pago es para a comision de luz "<<'\n';
			cout<<" digite la opcion que desea ";cin>>opc;
				switch(opc)
				{
					case 1:
						  
						 	saldo_inicial=saldo_inicial-monto;
						 	pag_agua+=monto;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   cout<<"pago que ha hecho ala comision de agua: "<<pag_agua<<'\n';
						  
					 
						   
						   break;//fin del caso 1
					case 2:  
					   	
						 	saldo_inicial=saldo_inicial-monto;
						 	pag_luz+=monto;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   cout<<"pago que ha hecho ala comision de agua: "<<pag_luz<<'\n';
						  
						  
					break;
			}
		}
		else
		{
		  cout<<"no tiene suficiente dinero para transferir o digite numeros mayores que cero "<<'\n';
			
		}
		
		
		
	}//cierre de la funcion pagos 
 
 //comienzo del int main 

int main() {
	decision();
	system ("cls");
	
while(contador!=3)
{
	  
		cout<<" \n ingrese el nombre del usuario: "; cin>>usuario;
		cout<<" \n ingrese el password del usuario: "; cin>>nip;
		 buscar_nip();
		if(busqueda==true)
		{
			
	   system("cls");		
	do{
	
		 contador=0;
		 leer_datos();
			
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
			cout<<"presione 7.- para cambiar de usuario "<<'\n';
			
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
                      	 deposito(monto);  
                      	  guardar_datos();
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
					   retiro(monto_2);	
					   	guardar_datos();
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
				    break;
					break;
					
				default:
					cout<<"opcion invalida"<<endl;
					
				break;
						
				
			}   //termina el switch
			cout<<endl;	
			system("pause");
			system("cls");
				
				
}while(opc!=7); // termino del ciclo while condicion para que cuando el usuario de mas de 3 intentos se cierre el programa	}while(respuesta!=2);	

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
