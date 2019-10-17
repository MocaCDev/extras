package setup.setup.setup;

import get_setup.get_setup.get_setup.get_setup;
import complete.complete.complete.complete;

public abstract class setup implements get_setup {
  public String network_type;
  public String net_use_as;
  public complete c = new complete();
  @Override
  public String net_type(String type) {
    this.network_type = type;
    return this.network_type;
  }
  @Override
  public String use_as(String use_net_as) {
    this.net_use_as = use_net_as;
    return this.net_use_as;
  }
  @Override
  public boolean is_ready() {
    if(this.network_type != "" && this.net_use_as != "") {
      c.COMPLETE_WITH_CONNECTION(this.network_type,this.net_use_as);
    }
    return c.RETURN();
  }
}
