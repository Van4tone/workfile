/*****************************FIR***************************************/
conf/local.conf    // board configure

ls source/meta-fsl-arm/conf/machine/*.conf -l   // display all the configure fsl-board    
*/

ls source/meta-fsl-arm-extra/conf/machine/*.conf -l   // display non-Freescale boards */

// Directory tree
//
//
//
//
// tmp/work/imx6qsabresd-poky-linux-gnueabi/linux-imx/3.0.35-r37.14/temp 
//under temp ,lots of log.* and run*
//for each package you will be able to see the log for latest task,and what was
//done on the latest task. For example
//log.dp_compile   --shows the log output from latest do_compile made for kernel
//run.do_compile   -- shows the compile command line 
//in order to konw the task and the task sequence take a look to log.taskorder
//file.
//
//
/*********************SEC***************************************/
tmp/deploy/image/imx6qsabresd/

//this Directory shows all image
//
//The symbolic link points to the latest created image 
//
//The .ext3 is EXT3 image for the rootfs.(you can copy it directory to SD card
//using dd:$sudo dd if=core-image-base.ext3 of=/dev/sdb2 
//
//  The .sdcard file is the compile image to be copied to sdcard .it's
//u-boot+uImage+rootfs 
//
//  The .tar.bz2 file is the tarball for rootfs ,you can extract it on your PC
//  uImage is latest kernel image
//  u-boot is the latest u-boot image 
//
//  bitbake the biggest image : bitbake fsl-image-gui 

/*******************************THR**********************************************/
//how the sdcard image generated 
//git.yoctoproject.org/cgit/cgit.cgi/meta-fsl-arm/tree/classes/

// Deploy the sdcard image 
//  sudo dd if=fsl-image-gui-imx6qsabresd.sdcard of=/dev/sdX bs=1M
// or deploy the ext3 rootfs 
//  sudo dd if=fsl-image-gui-imx6qsabresd.ext3 of=/dev/sdX2 bs=1M
// or deploy only the tar.gz rootfs 
//  sudo mount /dev/sdX2 /mnt/card 
//  sudo tar xf imagename-imx53qsb.tar.bz2 -C /mnt/card 
//
//in order to deploy only kernel
//  sudo cp uImage-3.0.35-r32.10-imx6qsabresd-22222.bin /media/Boot 
//
//in order to deploy only u-boot 
//  sudo dd if=u-boot-imx6qsabresd-v2012.10-r3.imx of=/dev/sdX bs=512 seek=2
//
//you can use your own. But double check the u-boot bootenv
//
/*******************************4TH****************************************/
// kernel 类别
//
// meta-fsl-arm there are 3 kernel recipes
//
//  linux-fslc_3.8.bb ---> kernel mainline(from kernel.log)
//  linux-imx_2.6.35.3.bb --->kernel from FSL,for imx5x and imx28
//  linux-imx_3.0.35.bb  --->kernel from FSL for imx6 
//
// 修改内核配置
//
// 1.创建新的配置（defconfig)
//  copy it to meta-fsl-arm/recipes-kernel/linux/linux-imx-3.0.35/mx6 (or the
//  right folder for your board/kernel)
//
//  bitbake -c cleansstate linux-imx 
//  bitbake linux-imx (if you want only the kernel image)
// 
// 2.make menuconfig with yocto 
//  bitbake -c menuconfig linux-imx 
//  it will generate a config file on
//  tmp/work/imx6qsabresd-poky-linux-gnueabi/linux-imx/3.0.35-r33.10/git/.config 
//
// 3.complete step by step to change the kernel confiuration
// bitbake -c menuconfig linux-imx 
//
// cp tmp/work/imx6qsabresd-poky-linux-gnueabi/linux-imx/3.0.35-r33.10/git/.config  /source/meta-fsl-arm/recipes-kernel/linux/linux-imx-3.0.35/mx6/defconfig 
// bitbake -c cleansstate linux-imx 
// bitbake fsl-image-gui 
//
//
//
/*********************************************************************************************/
//                        CUSTOMIZE THE IMAGE
//
   bitbake -s  // shows any available package locall 
   bitbake -s |grep calibrat          // grep for the name of desired package       
   calibrateproto
   libxcakibrate
   xinput-calibrator
//For example the package name is xinput-calibrat , in order to include this
//package this would be the string needed.
//
//
//
//
/***********************CREATE TOOLCHAIN************************************/
// 1.
//   bitbake meta-toolchain 
//   it does take some time to buid.
//   the toolchain in the /tmp/deploy/sdk/
//
// 2. build kernel manually using created toolchain
//    in order to install it:
//    source poky-eglibc-x86_64-arm-toolchain-1.4.1.sh 
// 3.source /opt/poky/1.4.1/environment-setup-armv7a-vfp-neon-poky-linux-gnueabi
// cd linux-2.6-imx 
// git checkout remotes/origin/imx_3.0.35 
// export ARCH=arm 
// export CROSS_COMPILE=$TARGET_PREFIX
// unset LDFLAGS
// make imx6_defconfig
// make uImage 
//
// Make sure to have mkimage available on bin patch 
// sudo apt-get install uboot-mkimage 




































