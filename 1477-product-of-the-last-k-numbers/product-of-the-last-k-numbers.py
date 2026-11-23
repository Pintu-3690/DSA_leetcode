class ProductOfNumbers:

    def __init__(self):
        self.prefixes = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.prefixes = [1]
        else:
            self.prefixes.append(self.prefixes[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.prefixes):
            return 0
        return self.prefixes[-1] // self.prefixes[-1 - k]