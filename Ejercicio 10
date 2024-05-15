import multiprocessing as mp
def serie(procesador,limite):
  r=""
  for i in range(procesador,limite+1):
    r=r+str((i+1)*2)+","
  return r
if _name=="main_":
  limite=100
  entradas=[(int(i*limite/mp.cpu_count()),int((i+1)*limite/mp.cpu_count())) for i in range(mp.cpu_count())]
  pool=Pool()
  re=pool.starmap(serie,entradas)
  print(re[0]+re[1])
