using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoWhile {
    public class DoWhile {
        public static int GetAge(int age) {
            Console.WriteLine(age);
            return age;
        }
        public static string Name(string name) {
            if(name == "Aidan") {
                Console.WriteLine("Hello Aidan");
                return name;
            } else {
                Console.WriteLine("Hello " + name);
                return name;
            }
        }
        public static void GetInfo(int ammount = 10, string pass = "admin") {
            do {
                for(; ammount > 0; ) {
                    Console.WriteLine("Decreased...is now " + ammount);
                    if(ammount == 1) {
                        pass = "adminadmin23";
                        break;
                    } else{
                        ammount -= 2;
                    }
                }
                Console.WriteLine("All done.");
            } while(ammount > 0 && pass == "admin");
        }
        public static void Main(string[] args) {
            GetAge(Convert.ToInt32(Console.ReadLine()));
            Name(Console.ReadLine());
            GetInfo();
        }
    }
}
