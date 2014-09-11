package helloworld;
import java.util.logging.Logger;
import.org.bukkit.ChatColor;
import.org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.plugin.Plugin;
import org.bukkit.plugin.java.JavaPlugin;
public class HelloWorld extends JavaPlugin {
	public static Logger = Logger.getLogger("Minecraft");
	public void onLoad(){
		log.info("[HelloWorld] Loaded.");
	}
	public void onEnable(){
		log.info("[HelloWorld] Starting Up.");
	}
	public void onDisable(){
		log.info("[HellowWorld] Stopping.");
	}
	public boolean onCommand(CommandSender sender, Command command, String commandLabel, String[] args){
		if (commandLabel.equalsIgnoreCase("hello")){
			String msg = "[Server] that's a nice thing";
			getServer().broadcastMessage(msg);
			return true;
		}
		return false;
	}
}