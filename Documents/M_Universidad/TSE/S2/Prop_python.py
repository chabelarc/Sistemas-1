# Primer ejercicio
# Data time

import datetime

x= datetime.datetime.now()

print ("La fecha es:")
print (x)
print ("Año:",x.year,"Mes:",x.strftime("%B"),"Día:",x.strftime("%A"),x.strftime("%d"))
print ("Hora:",x.strftime ("%H:%M:%S %p"))

#x.strftime("%A") Día
#x.strftime("%B") Mes
#x.strftime("%d") Numero
#x.strftime("%H:%M:%S %p") hora,minutos,segundos, AM/PM

#--------------------------------------------------------------------

#Segundo Ejercicio
#Numpy

#pip3 install numpy #Instalar numpy usando pip

import numpy as np

#Inspeccionando el arreglo

#Creando el arreglo

a = np.arange(15).reshape(3, 5) #Creando un arreglo con rango 0-14 de 3 por 5 (dimension)
b = np.zeros((3,5)) #Arreglo de ceros
c = np.ones ((2,3,4), dtype=np.int16) #Arreglo con 1's con tipo de datos enteros
d = np.ones ((3,5)) #Arreglo de 1's 

print ("La dimensión del arreglo a es \n",a.shape)

print ("El arreglo es :\n",a)

#a[0,0] = int(input("Introduzca un número entero para la primera entrada \n"))

#print ("El arreglo ahora es :\n",a)

#print ("El arreglo b es :\n",b)


#print ("El tamaño del arreglo c es \n",c.ndim)

a.shape #Dimension del arreglo
len(b) #Largo del arreglo
c.ndim #Numero de la dimensión del arreglo
a.size #Numero de elementos del arreglo
b.dtype #Tipo de dato de los elementos
c.dtype.name #Nombre del tipo de datos
c.astype(float) #Convertir el tipo de arreglo a otro

#Operaciones básicas matemáticas--------------

np.add (a,b) #Suma
np.subtract(a,b) #Resta
np.divide(a,d) #Division
np.multiply(a,d) #Multiplicacion
np.array_equal(a,b) #Comparacion de arreglos

#Agregar funciones -----------------------

a.sum () #Sumar arreglos entrada-entrada
a.min () #Mínimo valor del arreglo
a.mean() #Promedio
a.max(axis=0) #Máimo valor del arreglo
np.std(a) #Desviación estándar

#Preselección, cortado e índices--------------

a[1,2] # Selecciona el elemento de la fila 1, columna 2
a[0:2] # Selecciona los elementos con índicee 0 y uno
a[:1] #Selecciona todos los elementos de la fila 0
a[-1:] # Selecciona todos los elementos de la última fila
a[a<2] # Selecciona los elementos del arreglo que son menores que 2

#Manipulación del arreglo -------

np. transpose(a) # Transpone el arreglo
a.ravel() # Cambia el arreglo a una dimensión
a.reshape(5,-2) # Cambia la forma pero no los datos
np.append(a,b) #Agrega elementos al arreglo
np.concatenate((a,d), axis = 0) # Concatena arreglos
np.vsplit(a,3) # Separa el arreglo verticalmente en el tercer índice
np.hsplit(a, 5) # Separa el arreglo horizontalmente en el quinto índice

#Pandas -------------

#pip3 install pandas #Installar pandas
#pip3 install xlrd openpyxl #Installar xlrd y openpyxl

import pandas as pd

#Ejemplo de dataframe (estructura de datos)
df = pd.DataFrame ({'num_legs': [2, 4, np.nan, 0],
                    'num_wings':[2, 0, 0, 0],
                    'num_specimen_seen': [10,np.nan, 1,8] },
                   index=['falcon','dog','spider','fish'])
df #Muestra el dataframe
print(df)




