using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace myProject {
    public class main {
        public static void MakeTo(ref int numToChange, out int changed) {
            // This will be a estimated expression to change a number to
            // 100 if it is greater than 500, 500 if greater than 1000 etc
            
            int changed_ = 0;
            
            int initialAdd = 100;
            int initialSub = 150;
            int initialMult = 25;
            int initialDiv = 30;
            int doubled = 200;
            int triple = initialAdd * doubled / 50;
            
            if(numToChange >= 500 && numToChange < 1000) {
                changed_ = numToChange / initialDiv + (initialAdd * initialMult / 25) + 10;
            } else if(numToChange >= 1000 && numToChange < 1500) {
                changed_ = numToChange / initialDiv - (initialAdd * initialMult / 20) + 620;
            } else if(numToChange >= 1500 && numToChange < 10000) {
                changed_ = numToChange / initialDiv * initialMult / (initialAdd * initialMult / 30) + 1000;
            } else if(numToChange >= 10000 && numToChange < 1000000) {
                // We want to keep this around under 10000
                changed_ = numToChange / (initialAdd * initialMult / 2) * -doubled / -initialSub + (initialAdd * initialMult / 2) / numToChange;
            } else {
                // Anything the is a million plus will automatically be
                // reassigned to the max variable and will always end up
                // with the same result, being 2066446.
                if(numToChange == 1000000) {
                    // Same concept, same output, it is just defaulty here by catching a error
                    changed_ = numToChange / initialDiv * (initialMult + initialSub / 4) - (10 * triple / 20);
                } else {
                    int max = 1000001 - 1;
                    changed_ = max / initialDiv * (initialMult + initialSub / 4) - (10 * triple / 20);
                }
            }
            changed = changed_;
        }
        
        public static void Main(string[] args) {
            try {
                int a = Convert.ToInt32(Console.ReadLine());
                int b;
                MakeTo(ref a, out b);
                Console.WriteLine(b);
            } catch (System.OverflowException OFE) {
                int a = 1000001 - 1;
                int b;
                MakeTo(ref a, out b);
                Console.WriteLine(b);
            }
        }
    }
}
