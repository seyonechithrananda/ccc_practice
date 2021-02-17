

def rotate (arr, n):
    rotated = [n][n]
    for i in n:
        for j in n:
            rotated[i][j] = arr [n-j-1][i]

    return rotated

def getTable (table):