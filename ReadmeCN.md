# GTA5 菜单配置保存
将Saver代码保存到你的项目中，  
读取：在菜单中启动的部分（比如DllMain）中添加头文件，并在启动时调用函数ReadUIIni();  
保存：添加头文件UIManager.hpp，调用，例如g_UiManager->SaveIni();  
您可能需要修改一些东西，比如变量名，但是稍微细心点就OK了  


