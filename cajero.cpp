#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
string usuario="",nip="";
int respuesta=0, contador=0,opc=0;
double saldo_inicial=0,saldo_inicial2=0,saldo_inicial3=0,monto,transf=0;
double monto_2=0,retiro1=0,retiro2=0,retiro3=0;
string auxiliar="12345",auxiliar2="24689",auxiliar3="67890";
double deposito(double monto)
   {

   if(usuario=="axel" && nip==auxiliar)
   {
       
       saldo_inicial=saldo_inicial+monto;
       cout<<" dinero de su cuenta es : "<<saldo_inicial;
       cout<<endl;
       
    
   
   }
    
   else if(usuario =="juan" && nip ==auxiliar2)
   {
      
       saldo_inicial2=saldo_inicial2+monto;
       cout<<" dinero de su cuenta es : "<<saldo_inicial2;
       cout<<endl;    
       
       
   
   }
   else 
   {
   	
       saldo_inicial3=saldo_inicial3+monto;
       cout<<" dinero de su cuenta es : "<<saldo_inicial3;
       cout<<endl;    
         
       
   }
   return ((saldo_inicial)||(saldo_inicial2)||(saldo_inicial3));
}

//funcion para el retiro

 double retiro(double monto_2)
 {
 	
 	if(usuario=="axel")
 	{
 		if(saldo_inicial >= monto_2)
 		{
 			saldo_inicial = saldo_inicial - monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial;
 			cout<<endl;
 			
 			
		 }
 		
 		else{  
 				
 				cout<<"no tienes dinero en tu cuenta para retirar";
			 }  
			 
					 		 		 	 
	 }//cierre del if usuario axel
	   
	   if(usuario=="juan")		 
	  {
	  		if(saldo_inicial2 >= monto_2)
 		{
 			saldo_inicial2 =saldo_inicial2- monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial2;
 			cout<<endl;
 			
 			
		 }
 		
 		else{
 				
 				cout<<"no tienes dinero en tu cuenta para retirar";
			 }  
			 
	  	
	  }
	  
	  if(usuario=="francisco")
	  {
	  		if(saldo_inicial3 >= monto_2)
 		{
 			saldo_inicial3= saldo_inicial3 - monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial3;
 			cout<<endl;
 			
 			
		 }
 		
 		else{
 				
 				cout<<"no tienes dinero en tu cuenta para retirar";
			 }  
	  	
	  }
 	       			 
	return ((saldo_inicial)||(saldo_inicial2)||(saldo_inicial3));
 	
 } //cierre de la funcion retiro
 
 
  void  cambio_nip()
  {
  	cout<<"digite su usuario: ";cin>>usuario;
  	 cout<<endl;
  	 cout<<"ingrese su nip : ";cin>>nip;
  	 cout<<endl;
  	 
  	 if(usuario=="axel" && nip==auxiliar)
     {
     	cout<<" usuario :"<< usuario;
     	cout<<endl;
     	
     	cout<<"digite su nuevo nip: ";cin>>auxiliar;
     	nip=auxiliar;
     	cout<<"el cambio fue correcto ";
     	
      }//cierre de la condicional  nip axel
       
	   else if(usuario=="juan" && nip==auxiliar2)
	   {
	   	  cout<<" usuario : "<<usuario;
	   	  cout<<endl;
	   	  cout<<" digite su nuevo nip: ";cin>>auxiliar2;
	   	  nip=auxiliar2;
	   	  cout<<endl;
	   	  cout<<"el cambio de nip fue correcto: ";	  
	   	
	   }
	   else if(usuario=="francisco" && nip==auxiliar3)
	   {
	   	
	   	 cout<<" usuario : "<<usuario;
	   	  cout<<endl;
	   	  cout<<" digite su nuevo nip: ";cin>>auxiliar3;
	   	  nip=auxiliar3;
	   	  cout<<endl;
	   	  cout<<"el cambio de nip fue correcto: ";	  
	   	
	   }//cierre de la condicion auxiliar3
	    
	 	 else
       {
       	
       	cout<<"el nip que proporciono fue incorrecto";
       	
	   }// si el nip es incorrecto
	   
	   
  }//cierre de la funcion   cambio nip
 
 float transa()
 {
 	
   if(nip==auxiliar && usuario=="axel")
    {
       cout<<"ingresa el monto que vas a transferir: ";cin>>transf;
    	cout<<endl;
	     if(saldo_inicial>transf) 
	    {
	    	cout<<"ingrese el nip al que va transferir dinero: "; cin>>nip;
	    	cout<<endl;
	    	
	    	 if(nip==auxiliar2)
	    	{
	    		saldo_inicial2=saldo_inicial2+transf;
	    		
	    		saldo_inicial=saldo_inicial-transf;
	    		
	    		cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial2;
	    		
	    		
			}
	
		
		
	      
	         else if(nip == auxiliar3)
	    	{
	    		
	    		saldo_inicial3=saldo_inicial3+transf;
	    		saldo_inicial=saldo_inicial-transf;
	    		
	    	cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial3;
	    		
			}
			
	      	else
	    {
	    	cout<<"el nip que proporciono es incorrecto";
		}
		
		
		}//fin de la condicional del saldo
	     
		
    	 	else
        {
        	
        	cout<<"no  tienes suficiente dinero para transferir: ";
		}
	
 	
    
	}//fin del nip axel
	
	
	//aqui empieza la comparacion juan
	if(nip==auxiliar2 && usuario=="juan")
    {
       cout<<"ingresa el monto que vas a transferir: ";cin>>transf;
    	cout<<endl;
	     if(saldo_inicial2>transf) 
	    {
	    	cout<<"ingrese el nip al que va transferir dinero: "; cin>>nip;
	    	cout<<endl;
	    	
	    	if(nip == auxiliar)
	    	{
	    		saldo_inicial=saldo_inicial+transf;
	    		
	    		saldo_inicial2=saldo_inicial2-transf;
	    		
	    		cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial;
	    		cout<<endl;
	    		
	    		
			}
		
		
	      
	         else if(nip==auxiliar3)
	    	{
	    		
	    		saldo_inicial3=saldo_inicial3+transf;
	    		saldo_inicial2=saldo_inicial2-transf;
	    		
	    	cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial3;
	    	cout<<endl;
	    		
			}
			
	    	else
	    {
	    	cout<<"el nip que proporciono es incorrecto";
		}
		
		
		}//fin de la condicional del saldo
	
    	 	else
        {
        	
        	cout<<"no  tienes suficiente dinero para transferir: ";
		}
	
       } //aqui termina la condicion del usuario 2
       
       //aqui comienza la transferencia francisco
       if(nip==auxiliar3 && usuario=="francisco")
    {
       cout<<"ingresa el monto que vas a transferir: ";cin>>transf;
    	cout<<endl;
	     if(saldo_inicial3>transf) 
	    {
	    	cout<<"ingrese el nip al que va transferir dinero: "; cin>>nip;
	    	cout<<endl;
	    	
	    	if(nip == auxiliar)
	    	{
	    		saldo_inicial=saldo_inicial+transf;
	    		
	    		saldo_inicial3=saldo_inicial3-transf;
	    		
	    		cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial;
	    		cout<<endl;
	    		
	    		
			}
		
		
	      
	         else if(nip==auxiliar2)
	    	{
	    		
	    		saldo_inicial2=saldo_inicial2+transf;
	    		saldo_inicial3=saldo_inicial3-transf;
	    		
	    	cout<<" transferencia exitosa su saldo actual es : "<<saldo_inicial2;
	    	cout<<endl;
	    		
			}
			
	    	else
	    {
	    	cout<<"el nip que proporciono es incorrecto";
		}
		
		
		}//fin de la condicional del saldo
	
    	 	else
        {
        	
        	cout<<"no  tienes suficiente dinero para transferir: ";
		}
	
       }
       
       
 	 
 	}//fin de la funcion transacciones 
 
    void consulta()
    {
    	system("cls");
    	if(usuario=="axel" &&(nip==auxiliar))
    	{
    	
		   cout<<" su saldo actual es: "<<saldo_inicial;
		   cout<<endl;	
    		
		}//fin del if axel
    	
    	else if(usuario=="juan" && (nip==auxiliar2))
    	{
    		cout<<" su saldo actual es: "<<saldo_inicial2;
		   cout<<endl;	
    		
		}
		else if(usuario=="francisco" && (nip==auxiliar3))
		{
				cout<<" su saldo actual es: "<<saldo_inicial3;
		       cout<<endl;	
			
		}
    	else 
    	{
    		cout<<" ADVERTENCIA, el nip  que proporciono no existe"<<endl;
    		
		}
	}//cierre de la funcion consulta de saldo
 
 //comienzo del int main 

int main() {
while(contador!=3)
{
		cout<<" \n ingrese el nombre del usuario: "; cin>>usuario;
		cout<<" \n ingrese el password del usuario: "; cin>>nip;
		 
		if ((usuario == "axel" && nip == auxiliar)||(usuario == "juan" && nip == auxiliar2)||(usuario=="francisco" && nip==auxiliar3))
		{
	   system("cls");		
	do{
		 

		{
			
				
			
			
			cout<<" bienvenido al banco garcia";
			cout<<endl;
			cout<<"_______________________________";
			cout<<endl;
			cout<<"presione 1.- para deposito"<<endl;           //hacemos un menu para el usuario
			cout<<"presione 2.- para retiro"<<endl;
			cout<<"presion 3.- para cambiar nip"<<endl;
			cout<<"presione 4.- para hacer transacciones"<<endl;
			cout<<"presione 5.- para consultar su saldo"<<endl;
			cout<<"presione 6.- para cambiar de usuario "<<endl;
			
			cout<<"____________________________________"<<endl;
			
			cout<<"elija una opcion: ";cin>>opc; //leemos la opcion para el menu
			system("cls");
			switch(opc)
			
			{
				  
				case 1:
					
					  cout<<" deposito de dinero: "<<endl;
					  cout<<"ingrese el monto que quiere depositar: "; 
					  cin>>monto;
                      cout<<endl; 
					  deposito(monto);  
				break;
				
					
				case 2:
				
					cout<<" retiro bancarias"<<endl;
					cout<<"ingrese el monto que quiere retirar: "; 
					  cin>>monto_2;
					  retiro(monto_2);
					
				break;
					
				case 3:
					
					cout<<"cambio de nip:"<<endl;
					 cambio_nip();
					break;
					case 4:
						system("cls");
						 cout<<"transacciones:"<<endl;
						  transa();
						 break;
						 
					case 5:
					
						cout<<"consulta de saldo: "<<endl;
						   consulta();
						break;
						
					
				   case 6:
				    break;
					break;
					
				default:
					cout<<"opcion invalida"<<endl;
					
				break;
						
				
			}   //termina el switch
			cout<<endl;	
			system("pause");
			system("cls");
		}			
				
}while(opc!=6); // termino del ciclo while condicion para que cuando el usuario de mas de 3 intentos se cierre el programa	}while(respuesta!=2);	

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
