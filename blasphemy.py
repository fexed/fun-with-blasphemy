import sys
import random
from nltk import CFG, ChartParser

N_COMPLEMENTS = 7
N_VERBS = 7
CONST = 100

grammar = CFG.fromstring("""
S -> "s"X
X -> "i"X | "v""c"X
""")

def produce(starting_symbol, max_length):
    words = []
    productions = grammar.productions(lhs = starting_symbol)
    production = random.choice(productions)
    for sym in production.rhs():
            if isinstance(sym, str):
                words.append(sym)
                if (len(words) > max_length): break;
            else:
                words.extend(produce(sym, max_length - 1))
    return words


def random_line(afile):
    lines = afile.read().splitlines()
    myline = random.choice(lines)
    afile.seek(0)
    return myline


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("usage:", sys.argv[0], " <n produzioni> <lunghezza>")
        exit(1)

    n_prod = int(sys.argv[1])
    length = int(sys.argv[2])

    prods = []
    for prod in range(n_prod):
        prods.append(produce(grammar.start(), length))


    insultiF = open("insulti/insultiF.txt", "r")
    insultiM = open("insulti/insultiM.txt", "r")
    santiF = open("santi/santiF.txt", "r")
    santiM = open("santi/santiM.txt", "r")
    verbiMezzo = open("verbi/verbi_C_mezzo.txt", "r")
    verbiOggetto = open("verbi/verbi_C_oggetto.txt", "r")

    for p in prods:
        rnd = random.randint(1, 10)

        if rnd % 2 == 0:
            gender = 'M'
        else:
            gender = 'F'

        txt = ""
        for ch in p:
            if ch == 's':
                if gender == 'M': txt = txt + random_line(santiM) + " "
                else : txt = txt + random_line(santiM) + " "
            elif ch == 'i':
                if gender == 'M': txt = txt + random_line(insultiM) + " "
                else : txt = txt + random_line(insultiF) + " "
            elif ch == 'v':
                txt = txt + random_line(verbiOggetto) + " "
            elif ch == 'c':
                txt = txt + random_line(verbiMezzo) + " "
        print(txt.strip())

    insultiF.close()
    insultiM.close()
    santiF.close()
    santiM.close()
    verbiMezzo.close()
    verbiOggetto.close()
