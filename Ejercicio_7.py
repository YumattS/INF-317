import multiprocessing as mp
def calculo_pi(procesador,limite,procesadores):
  cpi=0
  for i in range(procesador,limite,procesadores):
    if(i!=0):
      cpi=cpi+1/(i*i)
  return cpi
if _name=="main_":
  limite=1000000
  entradas=[(i,limite,mp.cpu_count()) for i in range(mp.cpu_count())]
  pool=Pool()
  re=pool.starmap(calculo_pi,entradas)
  print((sum(re)* 6)**0.5)
