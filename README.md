# os-project  
## 生成方法  
* **这是使用32位ubuntu生成的版本，已写入镜像，在64位下如无更改，直接输入bochs回车即可，重新生成会导致错误。**  
* cd命令进入所在目录后，输入make image并回车  
* 若想安装应用（使用命令），cd command，make install，cd ..  
* 输入bochs回车  
* 可以使用alt或ctrl加F1，F2等切换窗口（确保系统的这些快捷键未被使用）  
## 实现内容  
* 增加开机提示和控制台提示  
* help：显示命令列表  
* rm：删除文件  
* show：显示文件内容  
* edit：编辑文件内容  
* mkfile：创建文件  
* ls：显示文件列表  
* echo：回显所输入字符，pwd：显示当前目录  
* 安装应用和使用shell  
* 能够使用Ctrl/Alt+F1/F2/F3切换多窗口，避免某些环境下的快捷键占用  
* 拥有文件系统和内存管理  
* 键盘输入及输出显示  
* 进程正常创建，中断，调用，通信  
* 拥有内核  
* 能够正常引导，中断，进入保护模式  
## 注意事项  
* 测试环境ubuntu32位，需安装bochs，nasm，gcc  
* bochrsc最后一行已改为keyboard: keymap=/usr/local/share/bochs/keymaps/x11-pc-us.map，若出现问题请查找类似目录下该文件存放位置  
* Makefile中，CFLAGS=后边应添加-m32以及-fno-stack-protector，LDFLAGS=后应添加-m elf_i386，因为64位系统和nasm、gcc的默认32位不兼容  
* 需要安装libc6-dev-i386，即sudo apt-get install ...，否则可能会提示/usr/include/features.h:424:12: fatal error: sys/cdefs.h: No such file or directory  #  include <sys/cdefs.h>  
* 部分生成的文件未被ignore  
* make前确保有目录/mnt/floppy/，否则使用mkdir创建  
* 若提示80m.img的错误，尝试删除80.img和80.img.lock（如果有），并重新解压一份复制到根目录  
* 部分环境下可能需要将bochsrc中修改为romimage: file=/usr/local/share/bochs/BIOS-bochs-latest和vgaromimage: file=/usr/local/share/bochs/VGABIOS-lgpl-latest  
## commit内容 
* 增加一些提示和指令help，rm等  
* 增加mkfile，cat（显示文件内容）   
* 增加了ls指令。可以使用Ctrl+F1，F2切换窗口了  
* 这是使用32位ubuntu生成的版本，可正常运行安装的应用程序，如echo。已写入镜像，在64位下如无更改，直接输入bochs回车即可，重新生成会导致错误。bochsrc有相应修改。80m.img不再被ignore。  
* 在mm/forkexit.c进行修改，使fork能够运行  
* 在kernel/hd.c中增加输出以使应用能够安装  
* 参考书中11.1，即示例代码chapter11/a，实现除从硬盘引导外的功能  
* 根目录下应有一个80m.img，为80M的镜像，由于过大，未上传，可从实例代码中找到80m.img.gz解压获得  
