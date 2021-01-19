#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
string usuario="",nip="";
int respuesta=0, contador=0,opc=0;
double saldo_inicial=0,saldo_inicial2=0,saldo_inicial3=0,monto,transf=0,pag_agua=0,pag_agua2=0,pag_agua3=0,pag_luz=0,pag_luz2=0,pag_luz3=0;
double monto_2=0,retiro1=0,retiro2=0,retiro3=0;
string auxiliar="1234",auxiliar2="2468",auxiliar3="6789";
double deposito(double monto)
   {

   if(usuario=="1234567890" && nip==auxiliar)
   {
       
       saldo_inicial=saldo_inicial+monto;
       cout<<" dinero de su cuenta es : "<<saldo_inicial;
       cout<<endl;
       
    
   
   }
    
   else if(usuario =="1234512345" && nip==auxiliar2)
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
 	
 	if(usuario=="1234567890")
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
			 
					 		 		 	 
	 }//cierre del if usuario axel
	   
	   if(usuario=="1234512345")		 
	  {
	  		if(saldo_inicial2 >= monto_2 && monto_2>0)
 		{
 			saldo_inicial2 =saldo_inicial2- monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial2;
 			cout<<endl;
 			
 			
		 }
 		
 		else{
 				
 				cout<<"no tienes dinero en tu cuenta para retirar";
			 }  
			 
	  	
	  }
	  
	  if(usuario=="6789067890")
	  {
	  		if(saldo_inicial3 >= monto_2 && monto_2>0)
 		{
 			saldo_inicial3= saldo_inicial3 - monto_2;
 			cout<<" dinero en cuentas es :"<<saldo_inicial3;
 			cout<<endl;
 			
 			
		 }
 		
 		else{
 				
 				cout<<"no tienes suficiente  dinero en tu cuenta para retirar o el numero es menor que 0";
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
  	 
  	 if(usuario=="1234567890" && nip==auxiliar)
     {
     	cout<<" usuario :"<< usuario<<endl;
     	
     	cout<<"digite su nuevo nip: ";cin>>auxiliar;
     
     	
     	nip=auxiliar;	
     	cout<<"el cambio fue correcto ";
			 		
     	
      }//cierre de la condicional  nip axel
       
	   else if(usuario=="1234512345" && nip==auxiliar2)
	   {
	   	  cout<<" usuario : "<<usuario;
	   	  cout<<endl;
	   	  cout<<" digite su nuevo nip: ";cin>>auxiliar2;
	   	  nip=auxiliar2;
	   	  cout<<endl;
	   	  cout<<"el cambio de nip fue correcto: ";	  
	   	
	   }
	   else if(usuario=="6789067890" && nip==auxiliar3)
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
  
  double transfe()
  {
  	 
  	 string nom_tarjeta;
  	 int transa=0;
  	cout<<" ingrese el numero de tarjeta ";cin>>nom_tarjeta;
  	if(nom_tarjeta=="1234567890"|| nom_tarjeta=="1234512345" || nom_tarjeta=="6789067890")
  	{
  		 
  	   cout<<"ingrese el deposito "	;cin>>transa;
  	   if((transa<=saldo_inicial)  || (transa<=saldo_inicial2)|| (transa<=saldo_inicial3) && (transa>0))
  	   {
  	   	
  	   	 
  	   	 
  	   	if(usuario=="1234567890" && nom_tarjeta=="1234512345")
  	   	{
  	   		 saldo_inicial=saldo_inicial-transa;
  	   		 saldo_inicial2=saldo_inicial2+transa;
  	   		 
	    }
	    else if(usuario=="1234567890" && nom_tarjeta=="6789067890")
	    {
	    	
	    	saldo_inicial=saldo_inicial-transa;
  	   		 saldo_inicial3=saldo_inicial3+transa;
	    	
		}
		
		else if(usuario=="1234512345" && nom_tarjeta=="1234567890")
		{
		    saldo_inicial2=saldo_inicial2-transa;
  	   		 saldo_inicial=saldo_inicial+transa;
  	   		 	
		}
		
		else if(usuario=="1234512345" && nom_tarjeta=="6789067890")
		{
		   saldo_inicial2=saldo_inicial2-transa;
  	   		 saldo_inicial3=saldo_inicial3+transa;	
		}
		
			else if(usuario=="6789067890" && nom_tarjeta=="1234567890")
  	   	{
  	   		 saldo_inicial3=saldo_inicial3-transa;
  	   		 saldo_inicial=saldo_inicial+transa;
  	   		 
  	   	
	    }
	    else if(usuario=="6789067890" && nom_tarjeta=="1234512345")
	    {
	    		 saldo_inicial3=saldo_inicial3-transa;
  	   		 saldo_inicial2=saldo_inicial2+transa;
	    	
		}
  	cout<<"transferencia exitosa , el monto transferido fue de:"<< transa;
  	   
  	
	  
	  }
	  
  	 else
		 {
  	   	
  	   	   cout<<" advertencia la tranasaccion debe de ser mayor a 0 o la transaccion debe de ser menor al saldo";
		 }  
  	   
  	  
	}
	
	    		else
	{
		cout<<"no encontro el usuario";
		cout<<endl;
	}
  		

  	 
  	
  }//cierre de la funcion transfe
 
 
 
    void consulta()
    {
    	 cout<<" digite su nip para realizar la consulta: ";cin>>nip;
    	
    	if(nip==auxiliar)
    	{
    	
		   cout<<" su saldo actual es: "<<saldo_inicial;
		   cout<<endl;	
    		
		}//fin del if axel
    	
    	else if (nip==auxiliar2 )
    	{
    		cout<<" su saldo actual es: "<<saldo_inicial2;
		   cout<<endl;	
    		
		}
		else if(nip==auxiliar3 )
		{
				cout<<" su saldo actual es: "<<saldo_inicial3;
		       cout<<endl;	
			
		}
    	else 
    	{
    		cout<<" ADVERTENCIA, el nip  que proporciono no existe"<<endl;
    		
		}
	}//cierre de la funcion consulta de saldo
	
	double pagos()
	{
		cout<<" digite el monto que va pagar ";cin>>monto;
		if((saldo_inicial>=monto && monto>0)||(saldo_inicial2>=monto && monto>0)||(saldo_inicial3>=monto && monto>0)) 
		{
				cout<<" digite 1.- si su pago para la comision de agua "<<'\n';
			cout<<" digite 2.- si su pago es para a comision de luz "<<'\n';
			cout<<" digite la opcion que desea ";cin>>opc;
				switch(opc)
				{
					case 1:
						  if (usuario=="1234567890")
						  {
						 	saldo_inicial=saldo_inicial-monto;
						 	pag_agua+=monto;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   cout<<"pago que ha hecho ala comision de agua: "<<pag_agua<<'\n';
						  
						  }
						   else if(usuario=="1234512345")
						   {
						   	 saldo_inicial2=saldo_inicial2-monto;
						   	 pag_agua2+=monto;
						   	 cout<<" el  pago transferido ala comision de agu es de  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial2;
						    cout<<"pago que ha hecho ala comision de agua: "<<pag_agua2<<'\n';
						   }
						   else
						   {
						   	saldo_inicial3=saldo_inicial3-monto;
						   	pag_agua3+=monto;
						   	cout<<" el  pago transferido ala comision de agu es de  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial3;
						    cout<<"pago que ha hecho ala comision de agua: "<<pag_agua3<<'\n';
						   }
						   
						   break;//fin del caso 1
					case 2:  
					   if (usuario=="1234567890")
						  {
						 	saldo_inicial=saldo_inicial-monto;
						 	pag_luz+=monto;
						   cout<<" el  pago que usted transfirio ala comision de agua es  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial<<'\n';
						   cout<<"pago que ha hecho ala comision de agua: "<<pag_luz<<'\n';
						  
						  }
						   else if(usuario=="1234512345")
						   {
						   	 saldo_inicial2=saldo_inicial2-monto;
						   	 pag_luz2+=monto;
						   	 cout<<" el  pago transferido ala comision de agu es de  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial2;
						    cout<<"pago que ha hecho ala comision de agua: "<<pag_luz2<<'\n';
						   }
						   else
						   {
						   	saldo_inicial3=saldo_inicial3-monto;
						   	pag_luz3+=monto;
						   	cout<<" el  pago transferido ala comision de agu es de  : " <<monto<<'\n';
						   cout<<" su saldo actual es de: "<<saldo_inicial3;
						    cout<<"pago que ha hecho ala comision de agua: "<<pag_luz3<<'\n';
						   } 
				      
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
while(contador!=3)
{
		cout<<" \n ingrese el nombre del usuario: "; cin>>usuario;
		cout<<" \n ingrese el password del usuario: "; cin>>nip;
		 
		if ((usuario == "1234567890" && nip == auxiliar)||(usuario == "1234512345" && nip == auxiliar2)||(usuario=="6789067890" && nip==auxiliar3))
		{
	   system("cls");		
	do{
		 

		{
			
				
			
			
			cout<<" bienvenido al banco garcia";
			cout<<endl;
			
			if(nip==auxiliar)
			{
				
		       cout<<" saldo inicial: "<<saldo_inicial;
		       cout<<endl;
				
			}
			else if(nip==auxiliar2)
			{
			     cout<<" saldo inicial: "<<saldo_inicial2;
				 cout<<endl;	
			}
			
			 else
			 {
			   cout<<" saldo inicial: "<<saldo_inicial3;
			   cout<<endl;	
			   	
			 }
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

						
						 cout<<"Ingrese el Nip?:";
						 cin>>nip_aux;
						 if(nip_aux==nip)
						 {
						 	 
						     transfe();
						 	    
						 	
						 }
						 
						 break;
						 
					case 5:
					
						cout<<"consulta de saldo: "<<endl;
						   consulta();
						break;
						case 6:
							pagos();
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
		}			
				
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
