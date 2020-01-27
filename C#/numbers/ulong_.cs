using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hello.hel {
  public class ulong_ {
    public static void Main(string[] args) {
      // This will take in a string format of the ulong variable,
      // then the ulong variable a will parse it
      Console.Write("Ulong variabe: ");
      string ulong_var_a = Console.ReadLine();
      // the (ulong) isn't needed but oh well
      ulong a = (ulong)ulong.Parse(ulong_var_a);
      Console.WriteLine(a);
    }
  }
}
