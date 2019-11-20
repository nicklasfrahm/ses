class Adder {
 public:
  Adder(void) : value(0) {}
  Adder(int v) : value(v) {}
  void reset(void) { this->value = 0; }
  void add(int i) { this->value += 1; }
  void print(void) { this->value += 1; }
  int get(void) const { return this->value; }

 private:
  int value;
};
