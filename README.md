# os-project  
## commit内容  
* 修复了fork()的错误，涉及文件mm/forkexit.c  
* 参考书中11.1，即示例代码chapter11/a，实现除从硬盘引导外的功能  
* 根目录下应有一个80m.img，为80M的镜像，由于过大，未上传，可从实例代码中找到80m.img.gz解压获得  
## 注意事项  
* 测试环境ubuntu64位，需安装bochs，bxiamge，nasm，gcc  
* bochrsc最后一行已改为keyboard: keymap=/usr/local/share/bochs/keymaps/x11-pc-us.map，若出现问题请查找类似目录下该文件存放位置  
* Makefile中，CFLAGS=后边应添加-m32以及-fno-stack-protector，LDFLAGS=后应添加-m elf_i386，因为64位系统和nasm、gcc的默认32位不兼容  
* 需要安装libc6-dev-i386，即sudo apt-get install ...，否则会提示/usr/include/features.h:424:12: fatal error: sys/cdefs.h: No such file or directory  #  include <sys/cdefs.h>  
* 部分生成的文件未被ignore  
## 运行方法  
* cd命令进入所在目录后，输入make image并回车  
* 输入bochs回车  
