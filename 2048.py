
def compute2048():
    m, c = getInput()
    m = zeroOut(c, m)

    if (c == 0) :
        # c=0 means shift left hence only operating in each row
        for i in range(4):
            #total 4 conditions here if we break up them into two parts
            if m[i][0] == m[i][1] and m[i][2] == m[i][3]:
                m[i][0] *= 2
                m[i][2] *= 2
                m[i][1] = m[i][2]
                m[i][2], m[i][3] = 0,0
            elif m[i][0] == m[i][1] and m[i][2] != m[i][3]:
                m[i][0] *= 2
                m[i][1], m[i][2] = m[i][2], m[i][3]
                m[i][3] = 0
            elif m[i][0] != m[i][1] and m[i][2] == m[i][3]:
                m[i][2] *= 2
                m[i][3] = 0

            elif m[i][0] != m[i][1] and m[i][1] == m[i][2]:
                if m[i][1] == 0:
                    if m[i][0] == m[i][3]:
                        m[i][0] *= 2
                        for j in range(1,4):
                            m[i][j] = 0
                    else:
                        m[i][1] = m[i][3]
                        m[i][3] = 0
                else:
                    m[i][1] *= 2
                    m[i][2], m[i][3] = m[i][3], 0
            else:
                pass


    if (c == 1):
        # shift up so it is oprating within columns
        for j in range(4):
            if m[0][j] == m[1][j] and m[2][j] == m[3][j]:
                m[0][j] *= 2
                m[2][j] *= 2
                m[1][j] = m[2][j]
                m[2][j], m[3][j] = 0, 0
            elif m[0][j] == m[1][j] and m[2][j] != m[3][j]:
                m[0][j] *= 2
                m[1][j], m[2][j] = m[2][j], m[3][j]
                m[3][j] = 0
            elif m[0][j] != m[1][j] and m[2][j] == m[3][j]:
                m[2][j] *= 2
                m[3][j] = 0

            elif m[0][j] != m[1][j] and m[1][j] == m[2][j]:
                if m[1][j] == 0:
                    if m[0][j] == m[3][j]:
                        m[0][j] *= 2
                        for i in range(1,4):
                            m[i][j] = 0
                    else:
                        m[1][j] = m[3][j]
                        m[3][j] = 0
                else:
                    m[1][j] *= 2
                    m[2][j], m[3][j] = m[3][j], 0
            else:
                pass
    if (c == 2) :
        # exactly the same procedure as when c = 0 except we shift right
        for i in range(4):
            #total 4 conditions here if we break up them into two parts
            if m[i][0] == m[i][1] and m[i][2] == m[i][3]:
                m[i][3] *= 2
                m[i][1] *= 2
                m[i][2] = m[i][1]
                m[i][0], m[i][1] = 0,0
            elif m[i][0] == m[i][1] and m[i][2] != m[i][3]:
                m[i][1] *= 2
                m[i][0] = 0
            elif m[i][0] != m[i][1] and m[i][2] == m[i][3]:
                m[i][3] *= 2
                m[i][2], m[i][1] = m[i][1], m[i][0]
                m[i][0] = 0

            elif m[i][2] != m[i][3] and m[i][1] == m[i][2]:
                if m[i][2] == 0:
                    if m[i][0] == m[i][3]:
                        m[i][3] *= 2
                        for j in range(0,3):
                            m[i][j] = 0
                    else:
                        m[i][2] = m[i][0]
                        m[i][0] = 0
                else:
                    m[i][2] *= 2
                    m[i][1], m[i][0] = m[i][0], 0
            else:
                pass
    if (c == 3):
        # shift down so it is oprating within columns
        for j in range(4):
            if m[0][j] == m[1][j] and m[2][j] == m[3][j]:
                m[3][j] *= 2
                m[1][j] *= 2
                m[2][j] = m[1][j]
                m[0][j], m[1][j] = 0,0
            elif m[0][j] == m[1][j] and m[2][j] != m[3][j]:
                m[1][j] *= 2
                m[0][j] = 0
            elif m[0][j] != m[1][j] and m[2][j] == m[3][j]:
                m[3][j] *= 2
                m[2][j], m[1][j] = m[1][j], m[0][j]
                m[0][j] = 0
            elif m[3][j] != m[2][j] and m[1][j] == m[2][j]:
                if m[2][j] == 0:
                    if m[0][j] == m[3][j]:
                        m[3][j] *= 2
                        for i in range(0,3):
                            m[i][j] = 0
                    else:
                        m[2][j] = m[0][j]
                        m[0][j] = 0
                else:
                    m[2][j] *= 2
                    m[0][j], m[1][j] = 0, m[0][j]
            else:
                pass
    printAns(m)


def getInput():
    matrix = [
        [0,0,0,0],
        [0,0,0,0],
        [0,0,0,0],
        [0,0,0,0]
    ]

    for i in range(4):
         matrix[i] = list(map(int,input().split()))


    command = int(input())
    return matrix, command

def printAns(a = []):
    for i in range (4):
        for j in range (4):
            print(a[i][j], end=" ")
        print("")

def zeroOut(x, a = []):
    if x == 0:
        #move left
        for i in range(4):
            b = [0, 0, 0, 0]
            index = 0
            for j in range(4):
                if a[i][j] != 0:
                    b[index] = a[i][j]
                    index+=1
            a[i] = b
    if x == 2:
        #move right
        for i in range(4):
            b = [0, 0, 0, 0]
            index = 3
            for j in range(3, -1, -1):
                if a[i][j] != 0:
                    b[index] = a[i][j]
                    index-=1
            a[i] = b
    if x == 1:
        #move up
        for j in range(4):
            b = [0, 0, 0, 0]
            index = 0
            for i in range(4):
                if a[i][j] != 0:
                    b[index] = a[i][j]
                    index += 1
            for p in range(4):
                a[p][j] = b[p]
    if x == 3:
        #move down
        for j in range(4):
            b = [0, 0, 0, 0]
            index = 3
            for i in range(3, -1, -1):
                if a[i][j] != 0:
                    b[index] = a[i][j]
                    index -= 1
            for p in range(4):
                a[p][j] = b[p]
    return a



compute2048()

