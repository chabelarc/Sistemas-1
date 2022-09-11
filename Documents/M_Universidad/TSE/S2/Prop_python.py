# Primer ejercicio
# Data time

import datetime

x= datetime.datetime.now()

print ("La fecha es:")
print (x)
print ("Año:",x.year,"Mes:",x.strftime("%B"),"Día:",x.strftime("%A"),x.strftime("%d"))
print (x.strftime ("%H:%M:%S %p"))
