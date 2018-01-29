/*
 *This file is show the comonds about bitbake */
 * 
 * /
bitbake <image>  				 // add -k to continue building even errors are found in the tasks
bitbake <package> -c <task> 	 // 生成一个特定包的任务。默认任务的名字如：fetch/unpack/patch/configure/compile/install/package/package_write/build 
								// 如：bitbake linux-imx -f -c compile       
								//     bitbake linux-imx 
bitbake <image> -g -u depexp    // 显示镜像中包的依赖关系
								// 如显示fsl-image-gui 中所有的包
								// bitbake fsl-image-gui -g -u depexp
								// *这个命令将打开一个 UI
								// 窗口，所以他必须在主机的内部执行
bitbake <package> -c listtasks   // 列出包的所有任务
bitbake <package> -c devshell    //打开一个新的 shell (已经定义了需要的系统值）
bitbake virtual/kernel -c menuconfig   // 互动的内核配置
bitbake <image> -c fetchall              // 获取特定镜像的资源
bitbake-layers show-layers              // show layers

bitbake-layers show-recipes "*-image-*"   // show possible image to bake. without "*-image-*" ,it shows ALL recipes.
bitbake -g <image> && cat pn-depends.dot | grep -v -e '-native' |grep -v digraph |grep -v -e '-image' |awk '{print$1}'|sort|uniq
// show image's packages
bitbake -g <pkg> && cat pn-depends.dot | grep -v -e '-native' |grep -v digraph |grep -v -e '-image' |awk '{print$1}'|sort|uniq
// show package's dependencies
bitbake -v <image> 2>&1 |tee image_build.log    //

bitbake -s |grep <pkg>       //

































































