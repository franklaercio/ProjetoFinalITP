import matplotlib.pyplot as plot

def colocar(plot_, path_arquivo, titulo):
    content = [line.split(',') for line in open(path_arquivo, "r").readlines()]

    t = [float(line.pop()[:-1]) for line in content]
    s = [float(line[0]) for line in content]
    i = [float(line[1]) for line in content]
    r = [float(line[2]) for line in content]

    plot_.plot(s, 'blue', label='S')
    plot_.plot(i, 'red', label='I')
    plot_.plot(r, 'yellow', label='R')

    plot_.legend(title='Legenda:')
    plot_.title(titulo)

colocar(plot, "./cenarioZero.csv", 'Cenário Zero')
colocar(plot, "./cenarioUm.csv", 'Cenário 1')
colocar(plot, "./cenarioDois.csv", 'Cenário 2')

plot.show()