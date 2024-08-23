class Solution:

    def fractionAddition(self, expression: str) -> str:
        firstposflag = False
        numlist = []
        denlist = []
        numerator = 0

        if expression[0] != "-":
            firstposflag = True

        for i in range(len(expression)):
            if expression[i] == "/":

                if not numlist and firstposflag:
                    if(expression[0] == "1" and expression[i - 1] == "0"):
                        numlist.append(10)
                    else:
                        numlist.append(int(expression[i - 1]))
                else:
                    if (expression[i - 3] == "-"):
                        numlist.append(-10)
                    elif (expression[i - 2] == "-"):
                         numlist.append(-1 * int(expression[i - 1]))
                    elif (expression[i - 2] == "1"):
                        numlist.append(10)
                    else:
                        numlist.append(int(expression[i - 1]))

                if (expression[i + 1] == "1" and i == len(expression) - 3):
                    denlist.append(10)
                elif (expression[i + 1] == "1" and i == len(expression) - 2):
                    denlist.append(int(expression[i + 1]))
                elif (expression[i + 1] == "1" and expression[i + 2] == "0"):
                    denlist.append(10)
                else:
                    denlist.append(int(expression[i + 1]))

        denlcm = reduce(lcm, denlist)

        for i in range(len(numlist)):
            numerator += (numlist[i] * (denlcm / denlist[i]))
            numerator = int(numerator)
        cd = gcd(numerator, denlcm)

        return f"{numerator // cd}/{denlcm // cd}"

        





