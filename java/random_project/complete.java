package complete.complete.complete;

import java.util.ArrayList;
import java.io.File;
import java.io.FileWriter;

public class complete {
  public ArrayList<String> data = new ArrayList<String>();
  public String data_to_write;
  public void COMPLETE_WITH_CONNECTION(String network_type, String used_for) {
    this.data.add("DATA: \n" + network_type + "\n" + used_for);
    try {
      File write_ = new File("//home//runner//info.txt");
      FileWriter w = new FileWriter(write_);
      for(String d: this.data) {
        this.data_to_write = d;
      }
      w.write(this.data_to_write);
      w.close();
    } catch(Exception e) {
      System.out.println("Caught error\n\n" + e);
    }
  }
  public boolean RETURN() {
    if(this.data.size() > 0) {
      return true;
    } else {
      return false;
    }
  }
}
