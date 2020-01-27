using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace aProject {
  public class mainNumberFile {
    public static void Main(string[] args) {
      Console.Write("Number: ");
      int a = Convert.ToInt32(Console.ReadLine());
      for(; a > 0 ;) {
        Console.WriteLine("writing");
        if(a > 4 && a < 20) {
          a = a-4*-a;
          Console.WriteLine("Exit with status -> " + a);
          break;
        } else if (a > 10 && a < 40) {
          a = a-10*-a/3;
          Console.WriteLine("Exit with status -> " + a);
          break;
        } else {
          if(a >= 500 && a < 1000) {
            a = a * a / 2 + (a * a / 2) - 10;
          }else if(a >= 1000) {
            a = a * (a * a - 5000) + a * (a / 10) + 10;
          }
          if(a >= 100) {
              a = a / 2 * (a * a / 4) + (4 / 2 * 4) / 450;
              Console.WriteLine("status -> " + a);
              a-=2;
            if(a < 0) {
              Console.WriteLine("Exit with status -> " + a);
              break;
            }
          }
        }
        a -= 2;
      }
    }
  }
}
