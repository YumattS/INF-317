import multiprocessing as mp
from multiprocessing import Pool
def fibo(inicial,limite):
  w=[]
  t1=(1/pow(5,1/2))*pow(((1+pow(5,1/2))/2),inicial)
  t2=(1/pow(5,1/2))*pow(((1-pow(5,1/2))/2),inicial)
  a=round(t1-t2)
  t1=(1/pow(5,1/2))*pow(((1+pow(5,1/2))/2),inicial+1)
  t2=(1/pow(5,1/2))*pow(((1-pow(5,1/2))/2),inicial+1)
  b=round(t1-t2)
  for i in range(inicial,limite):
    w.append(a)
    a,b=b,a+b
  return w
if _name=="main_":
  limite=int(1000/mp.cpu_count())
  entrada=[(i*limite,limite*(i+1)) for i in range(mp.cpu_count())]
  pool=Pool()
  print(entrada)
  re=pool.starmap(fibo,entrada)
  print(re[0])
