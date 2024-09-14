# GTA5 菜单配置保存
将Saver代码保存到你的项目中，  
读取：在菜单中启动的部分（比如DllMain）中添加头文件，并在启动时调用函数ReadUIIni();  
保存：添加头文件UIManager.hpp，调用，例如g_UiManager->SaveIni();  
您可能需要修改一些东西，比如变量名，但是稍微细心点就OK了  


![image](https://github.com/user-attachments/assets/ebff53c3-2d77-4ca3-b29b-9b4d04950381)
![image](https://github.com/user-attachments/assets/34c616f6-79f0-405b-9fc3-b52625c01b77)
