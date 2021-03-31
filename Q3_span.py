
class ArrayStack:
    """LIFO Stack implementation using a Python list as underlying storage."""

    def __init__(self):
        """Create an empty stack."""
        self._data = []                       # nonpublic list instance

    def __len__(self):
        """Return the number of elements in the stack."""
        return len(self._data)

    def is_empty(self):
        """Return True if the stack is empty."""
        return len(self._data) == 0

    def push(self, e):
        """Add element e to the top of the stack."""
        self._data.append(e)                  # new item stored at end of list

    def top(self):
        """Return (but do not remove) the element at the top of the stack.

        Raise Empty exception if the stack is empty.
        """
        if self.is_empty():
            print('Stack is empty')
            exit(1)
        return self._data[-1]                 # the last item in the list

    def pop(self):
        """Remove and return the element from the top of the stack (i.e., LIFO).

        Raise Empty exception if the stack is empty.
        """
        if self.is_empty():
            print('Stack is empty')
            exit(1)
        return self._data.pop()               # remove last item from list


def span(X):
    """ find the span (as defined in class) of an array X """
    myStack = ArrayStack()  # stack to keep track of the last few toppers
    S = [0] * len(X)
    for i in range(len(X)):
        while (not myStack.is_empty() and X[myStack.top()] <= X[i]):
            myStack.pop()
        # now stack is empty or an index exists that is strictly larger
        if (myStack.is_empty()):
            S[i] = i+1
        else:
            S[i] = i-myStack.top()
        myStack.push(i)  # i is the next topper to be considered for items > i
    return S


if __name__ == '__main__':

    n = int(input())
    X = []

    X = [int(x) for x in input().split()]

    spanX = span(X)

    for i in spanX:
        print(i)