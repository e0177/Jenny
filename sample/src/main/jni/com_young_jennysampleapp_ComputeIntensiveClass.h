/* 
 * JNI Header file generated by annotation JNI helper
 * written by landerlyoung@gmail.com
 */

/* C/C++ header file for class com.young.jennysampleapp.ComputeIntensiveClass */
#ifndef _Included_com_young_jennysampleapp_ComputeIntensiveClass
#define _Included_com_young_jennysampleapp_ComputeIntensiveClass

#include <jni.h>
#include "JavaCallbackReflect.h"
static constexpr const char * const com_young_jennysampleapp_ComputeIntensiveClass_LOG_TAG = "ComputeIntensiveClass";
static constexpr const char * const com_young_jennysampleapp_ComputeIntensiveClass_KEY_WHERE_ARE_YOUT_FROM = "where_are_you_from";
static constexpr const jint com_young_jennysampleapp_ComputeIntensiveClass_IDEL = -1L;
static constexpr const jint com_young_jennysampleapp_ComputeIntensiveClass_BUSY = 1L;

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public int addInNative(int a, int b)
 * Signature: (II)I
 */
jint addInNative(JNIEnv *env, jobject thiz, jint a, jint b);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static void computeSomething(byte[] sth)
 * Signature: ([B)V
 */
void computeSomething(JNIEnv *env, jclass clazz, jbyteArray sth);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.String greet()
 * Signature: ()Ljava/lang/String;
 */
jstring greet(JNIEnv *env, jclass clazz);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public final void testParamParse(int a, java.lang.String b, long[] c, float[][] d, java.lang.Exception e, java.lang.Class<java.lang.String> f, java.util.HashMap<?,?> g)
 * Signature: (ILjava/lang/String;[J[[FLjava/lang/Exception;Ljava/lang/Class;Ljava/util/HashMap;)V
 */
void testParamParse(JNIEnv *env, jobject thiz, jint a, jstring b, jlongArray c, jobjectArray d, jthrowable e, jobject f, jobject g);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static long returnsLong()
 * Signature: ()J
 */
jlong returnsLong(JNIEnv *env, jclass clazz);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static boolean returnsBool()
 * Signature: ()Z
 */
jboolean returnsBool(JNIEnv *env, jclass clazz);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.Object returnsObject()
 * Signature: ()Ljava/lang/Object;
 */
jobject returnsObject(JNIEnv *env, jclass clazz);

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public int computeThenCallback(com.young.jennysampleapp.Callback listener)
 * Signature: (Lcom/young/jennysampleapp/Callback;)I
 */
jint computeThenCallback(JNIEnv *env, jobject thiz, jobject listener);

/*
 * registe Native functions
 */
void register_com_young_jennysampleapp_ComputeIntensiveClass(JNIEnv *env);

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved);
#ifdef __cplusplus
}
#endif

#endif //_Included_com_young_jennysampleapp_ComputeIntensiveClass
