/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#include "java_StringProxy.h"


// external logger function passed by jenny.errorLoggerFunction
void jennySampleErrorLog(const char* error);


namespace java {

jclass StringProxy::sClazz = nullptr;

// thread safe init
std::mutex StringProxy::sInitLock;
std::atomic_bool StringProxy::sInited;

/*static*/ bool StringProxy::initClazz(JNIEnv *env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
                jennySampleErrorLog("can't init StringProxy::" #val); \
               env->ExceptionDescribe();           \
               return false;                       \
           }                                       \
       } while(false)

    if (!sInited) {
        std::lock_guard<std::mutex> lg(sInitLock);
        if (!sInited) {
            auto clazz = env->FindClass(FULL_CLASS_NAME);
            JENNY_CHECK_NULL(clazz);
            sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(clazz));
            env->DeleteLocalRef(clazz);
            JENNY_CHECK_NULL(sClazz);

            sConstruct_0 = env->GetMethodID(sClazz, "<init>", "()V");
            JENNY_CHECK_NULL(sConstruct_0);

            sConstruct_1 = env->GetMethodID(sClazz, "<init>", "(Ljava/lang/String;)V");
            JENNY_CHECK_NULL(sConstruct_1);

            sConstruct_2 = env->GetMethodID(sClazz, "<init>", "([C)V");
            JENNY_CHECK_NULL(sConstruct_2);

            sConstruct_3 = env->GetMethodID(sClazz, "<init>", "([CII)V");
            JENNY_CHECK_NULL(sConstruct_3);

            sConstruct_4 = env->GetMethodID(sClazz, "<init>", "([III)V");
            JENNY_CHECK_NULL(sConstruct_4);

            sConstruct_5 = env->GetMethodID(sClazz, "<init>", "([BIII)V");
            JENNY_CHECK_NULL(sConstruct_5);

            sConstruct_6 = env->GetMethodID(sClazz, "<init>", "([BI)V");
            JENNY_CHECK_NULL(sConstruct_6);

            sConstruct_7 = env->GetMethodID(sClazz, "<init>", "([BIILjava/lang/String;)V");
            JENNY_CHECK_NULL(sConstruct_7);

            sConstruct_8 = env->GetMethodID(sClazz, "<init>", "([BIILjava/nio/charset/Charset;)V");
            JENNY_CHECK_NULL(sConstruct_8);

            sConstruct_9 = env->GetMethodID(sClazz, "<init>", "([BLjava/lang/String;)V");
            JENNY_CHECK_NULL(sConstruct_9);

            sConstruct_10 = env->GetMethodID(sClazz, "<init>", "([BLjava/nio/charset/Charset;)V");
            JENNY_CHECK_NULL(sConstruct_10);

            sConstruct_11 = env->GetMethodID(sClazz, "<init>", "([BII)V");
            JENNY_CHECK_NULL(sConstruct_11);

            sConstruct_12 = env->GetMethodID(sClazz, "<init>", "([B)V");
            JENNY_CHECK_NULL(sConstruct_12);

            sConstruct_13 = env->GetMethodID(sClazz, "<init>", "(Ljava/lang/StringBuffer;)V");
            JENNY_CHECK_NULL(sConstruct_13);

            sConstruct_14 = env->GetMethodID(sClazz, "<init>", "(Ljava/lang/StringBuilder;)V");
            JENNY_CHECK_NULL(sConstruct_14);


            sMethod_length_0 = env->GetMethodID(sClazz, "length", "()I");
            JENNY_CHECK_NULL(sMethod_length_0);

            sMethod_isEmpty_0 = env->GetMethodID(sClazz, "isEmpty", "()Z");
            JENNY_CHECK_NULL(sMethod_isEmpty_0);

            sMethod_charAt_0 = env->GetMethodID(sClazz, "charAt", "(I)C");
            JENNY_CHECK_NULL(sMethod_charAt_0);

            sMethod_codePointAt_0 = env->GetMethodID(sClazz, "codePointAt", "(I)I");
            JENNY_CHECK_NULL(sMethod_codePointAt_0);

            sMethod_codePointBefore_0 = env->GetMethodID(sClazz, "codePointBefore", "(I)I");
            JENNY_CHECK_NULL(sMethod_codePointBefore_0);

            sMethod_codePointCount_0 = env->GetMethodID(sClazz, "codePointCount", "(II)I");
            JENNY_CHECK_NULL(sMethod_codePointCount_0);

            sMethod_offsetByCodePoints_0 = env->GetMethodID(sClazz, "offsetByCodePoints", "(II)I");
            JENNY_CHECK_NULL(sMethod_offsetByCodePoints_0);

            sMethod_getChars_0 = env->GetMethodID(sClazz, "getChars", "(II[CI)V");
            JENNY_CHECK_NULL(sMethod_getChars_0);

            sMethod_getBytes_0 = env->GetMethodID(sClazz, "getBytes", "(II[BI)V");
            JENNY_CHECK_NULL(sMethod_getBytes_0);

            sMethod_getBytes_1 = env->GetMethodID(sClazz, "getBytes", "(Ljava/lang/String;)[B");
            JENNY_CHECK_NULL(sMethod_getBytes_1);

            sMethod_getBytes_2 = env->GetMethodID(sClazz, "getBytes", "(Ljava/nio/charset/Charset;)[B");
            JENNY_CHECK_NULL(sMethod_getBytes_2);

            sMethod_getBytes_3 = env->GetMethodID(sClazz, "getBytes", "()[B");
            JENNY_CHECK_NULL(sMethod_getBytes_3);

            sMethod_equals_0 = env->GetMethodID(sClazz, "equals", "(Ljava/lang/Object;)Z");
            JENNY_CHECK_NULL(sMethod_equals_0);

            sMethod_contentEquals_0 = env->GetMethodID(sClazz, "contentEquals", "(Ljava/lang/StringBuffer;)Z");
            JENNY_CHECK_NULL(sMethod_contentEquals_0);

            sMethod_contentEquals_1 = env->GetMethodID(sClazz, "contentEquals", "(Ljava/lang/CharSequence;)Z");
            JENNY_CHECK_NULL(sMethod_contentEquals_1);

            sMethod_equalsIgnoreCase_0 = env->GetMethodID(sClazz, "equalsIgnoreCase", "(Ljava/lang/String;)Z");
            JENNY_CHECK_NULL(sMethod_equalsIgnoreCase_0);

            sMethod_compareTo_0 = env->GetMethodID(sClazz, "compareTo", "(Ljava/lang/String;)I");
            JENNY_CHECK_NULL(sMethod_compareTo_0);

            sMethod_compareToIgnoreCase_0 = env->GetMethodID(sClazz, "compareToIgnoreCase", "(Ljava/lang/String;)I");
            JENNY_CHECK_NULL(sMethod_compareToIgnoreCase_0);

            sMethod_regionMatches_0 = env->GetMethodID(sClazz, "regionMatches", "(ILjava/lang/String;II)Z");
            JENNY_CHECK_NULL(sMethod_regionMatches_0);

            sMethod_regionMatches_1 = env->GetMethodID(sClazz, "regionMatches", "(ZILjava/lang/String;II)Z");
            JENNY_CHECK_NULL(sMethod_regionMatches_1);

            sMethod_startsWith_0 = env->GetMethodID(sClazz, "startsWith", "(Ljava/lang/String;I)Z");
            JENNY_CHECK_NULL(sMethod_startsWith_0);

            sMethod_startsWith_1 = env->GetMethodID(sClazz, "startsWith", "(Ljava/lang/String;)Z");
            JENNY_CHECK_NULL(sMethod_startsWith_1);

            sMethod_endsWith_0 = env->GetMethodID(sClazz, "endsWith", "(Ljava/lang/String;)Z");
            JENNY_CHECK_NULL(sMethod_endsWith_0);

            sMethod_hashCode_0 = env->GetMethodID(sClazz, "hashCode", "()I");
            JENNY_CHECK_NULL(sMethod_hashCode_0);

            sMethod_indexOf_0 = env->GetMethodID(sClazz, "indexOf", "(I)I");
            JENNY_CHECK_NULL(sMethod_indexOf_0);

            sMethod_indexOf_1 = env->GetMethodID(sClazz, "indexOf", "(II)I");
            JENNY_CHECK_NULL(sMethod_indexOf_1);

            sMethod_indexOf_2 = env->GetMethodID(sClazz, "indexOf", "(Ljava/lang/String;)I");
            JENNY_CHECK_NULL(sMethod_indexOf_2);

            sMethod_indexOf_3 = env->GetMethodID(sClazz, "indexOf", "(Ljava/lang/String;I)I");
            JENNY_CHECK_NULL(sMethod_indexOf_3);

            sMethod_lastIndexOf_0 = env->GetMethodID(sClazz, "lastIndexOf", "(I)I");
            JENNY_CHECK_NULL(sMethod_lastIndexOf_0);

            sMethod_lastIndexOf_1 = env->GetMethodID(sClazz, "lastIndexOf", "(II)I");
            JENNY_CHECK_NULL(sMethod_lastIndexOf_1);

            sMethod_lastIndexOf_2 = env->GetMethodID(sClazz, "lastIndexOf", "(Ljava/lang/String;)I");
            JENNY_CHECK_NULL(sMethod_lastIndexOf_2);

            sMethod_lastIndexOf_3 = env->GetMethodID(sClazz, "lastIndexOf", "(Ljava/lang/String;I)I");
            JENNY_CHECK_NULL(sMethod_lastIndexOf_3);

            sMethod_substring_0 = env->GetMethodID(sClazz, "substring", "(I)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_substring_0);

            sMethod_substring_1 = env->GetMethodID(sClazz, "substring", "(II)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_substring_1);

            sMethod_subSequence_0 = env->GetMethodID(sClazz, "subSequence", "(II)Ljava/lang/CharSequence;");
            JENNY_CHECK_NULL(sMethod_subSequence_0);

            sMethod_concat_0 = env->GetMethodID(sClazz, "concat", "(Ljava/lang/String;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_concat_0);

            sMethod_replace_0 = env->GetMethodID(sClazz, "replace", "(CC)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_replace_0);

            sMethod_replace_1 = env->GetMethodID(sClazz, "replace", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_replace_1);

            sMethod_matches_0 = env->GetMethodID(sClazz, "matches", "(Ljava/lang/String;)Z");
            JENNY_CHECK_NULL(sMethod_matches_0);

            sMethod_contains_0 = env->GetMethodID(sClazz, "contains", "(Ljava/lang/CharSequence;)Z");
            JENNY_CHECK_NULL(sMethod_contains_0);

            sMethod_replaceFirst_0 = env->GetMethodID(sClazz, "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_replaceFirst_0);

            sMethod_replaceAll_0 = env->GetMethodID(sClazz, "replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_replaceAll_0);

            sMethod_split_0 = env->GetMethodID(sClazz, "split", "(Ljava/lang/String;I)[Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_split_0);

            sMethod_split_1 = env->GetMethodID(sClazz, "split", "(Ljava/lang/String;)[Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_split_1);

            sMethod_join_0 = env->GetStaticMethodID(sClazz, "join", "(Ljava/lang/CharSequence;[Ljava/lang/CharSequence;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_join_0);

            sMethod_join_1 = env->GetStaticMethodID(sClazz, "join", "(Ljava/lang/CharSequence;Ljava/lang/Iterable;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_join_1);

            sMethod_toLowerCase_0 = env->GetMethodID(sClazz, "toLowerCase", "(Ljava/util/Locale;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_toLowerCase_0);

            sMethod_toLowerCase_1 = env->GetMethodID(sClazz, "toLowerCase", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_toLowerCase_1);

            sMethod_toUpperCase_0 = env->GetMethodID(sClazz, "toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_toUpperCase_0);

            sMethod_toUpperCase_1 = env->GetMethodID(sClazz, "toUpperCase", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_toUpperCase_1);

            sMethod_trim_0 = env->GetMethodID(sClazz, "trim", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_trim_0);

            sMethod_toString_0 = env->GetMethodID(sClazz, "toString", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_toString_0);

            sMethod_toCharArray_0 = env->GetMethodID(sClazz, "toCharArray", "()[C");
            JENNY_CHECK_NULL(sMethod_toCharArray_0);

            sMethod_format_0 = env->GetStaticMethodID(sClazz, "format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_format_0);

            sMethod_format_1 = env->GetStaticMethodID(sClazz, "format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_format_1);

            sMethod_valueOf_0 = env->GetStaticMethodID(sClazz, "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_0);

            sMethod_valueOf_1 = env->GetStaticMethodID(sClazz, "valueOf", "([C)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_1);

            sMethod_valueOf_2 = env->GetStaticMethodID(sClazz, "valueOf", "([CII)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_2);

            sMethod_valueOf_3 = env->GetStaticMethodID(sClazz, "valueOf", "(Z)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_3);

            sMethod_valueOf_4 = env->GetStaticMethodID(sClazz, "valueOf", "(C)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_4);

            sMethod_valueOf_5 = env->GetStaticMethodID(sClazz, "valueOf", "(I)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_5);

            sMethod_valueOf_6 = env->GetStaticMethodID(sClazz, "valueOf", "(J)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_6);

            sMethod_valueOf_7 = env->GetStaticMethodID(sClazz, "valueOf", "(F)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_7);

            sMethod_valueOf_8 = env->GetStaticMethodID(sClazz, "valueOf", "(D)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_valueOf_8);

            sMethod_copyValueOf_0 = env->GetStaticMethodID(sClazz, "copyValueOf", "([CII)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_copyValueOf_0);

            sMethod_copyValueOf_1 = env->GetStaticMethodID(sClazz, "copyValueOf", "([C)Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_copyValueOf_1);

            sMethod_intern_0 = env->GetMethodID(sClazz, "intern", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(sMethod_intern_0);


            sField_CASE_INSENSITIVE_ORDER_0 = env->GetStaticFieldID(sClazz, "CASE_INSENSITIVE_ORDER", "Ljava/util/Comparator;");
            JENNY_CHECK_NULL(sField_CASE_INSENSITIVE_ORDER_0);


            sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ void StringProxy::releaseClazz(JNIEnv *env) {
    if (sInited) {
        std::lock_guard<std::mutex> lg(sInitLock);
        if (sInited) {
            env->DeleteLocalRef(sClazz);
            sInited = false;
        }
    }
}

jmethodID StringProxy::sConstruct_0;
jmethodID StringProxy::sConstruct_1;
jmethodID StringProxy::sConstruct_2;
jmethodID StringProxy::sConstruct_3;
jmethodID StringProxy::sConstruct_4;
jmethodID StringProxy::sConstruct_5;
jmethodID StringProxy::sConstruct_6;
jmethodID StringProxy::sConstruct_7;
jmethodID StringProxy::sConstruct_8;
jmethodID StringProxy::sConstruct_9;
jmethodID StringProxy::sConstruct_10;
jmethodID StringProxy::sConstruct_11;
jmethodID StringProxy::sConstruct_12;
jmethodID StringProxy::sConstruct_13;
jmethodID StringProxy::sConstruct_14;

jmethodID StringProxy::sMethod_length_0;
jmethodID StringProxy::sMethod_isEmpty_0;
jmethodID StringProxy::sMethod_charAt_0;
jmethodID StringProxy::sMethod_codePointAt_0;
jmethodID StringProxy::sMethod_codePointBefore_0;
jmethodID StringProxy::sMethod_codePointCount_0;
jmethodID StringProxy::sMethod_offsetByCodePoints_0;
jmethodID StringProxy::sMethod_getChars_0;
jmethodID StringProxy::sMethod_getBytes_0;
jmethodID StringProxy::sMethod_getBytes_1;
jmethodID StringProxy::sMethod_getBytes_2;
jmethodID StringProxy::sMethod_getBytes_3;
jmethodID StringProxy::sMethod_equals_0;
jmethodID StringProxy::sMethod_contentEquals_0;
jmethodID StringProxy::sMethod_contentEquals_1;
jmethodID StringProxy::sMethod_equalsIgnoreCase_0;
jmethodID StringProxy::sMethod_compareTo_0;
jmethodID StringProxy::sMethod_compareToIgnoreCase_0;
jmethodID StringProxy::sMethod_regionMatches_0;
jmethodID StringProxy::sMethod_regionMatches_1;
jmethodID StringProxy::sMethod_startsWith_0;
jmethodID StringProxy::sMethod_startsWith_1;
jmethodID StringProxy::sMethod_endsWith_0;
jmethodID StringProxy::sMethod_hashCode_0;
jmethodID StringProxy::sMethod_indexOf_0;
jmethodID StringProxy::sMethod_indexOf_1;
jmethodID StringProxy::sMethod_indexOf_2;
jmethodID StringProxy::sMethod_indexOf_3;
jmethodID StringProxy::sMethod_lastIndexOf_0;
jmethodID StringProxy::sMethod_lastIndexOf_1;
jmethodID StringProxy::sMethod_lastIndexOf_2;
jmethodID StringProxy::sMethod_lastIndexOf_3;
jmethodID StringProxy::sMethod_substring_0;
jmethodID StringProxy::sMethod_substring_1;
jmethodID StringProxy::sMethod_subSequence_0;
jmethodID StringProxy::sMethod_concat_0;
jmethodID StringProxy::sMethod_replace_0;
jmethodID StringProxy::sMethod_replace_1;
jmethodID StringProxy::sMethod_matches_0;
jmethodID StringProxy::sMethod_contains_0;
jmethodID StringProxy::sMethod_replaceFirst_0;
jmethodID StringProxy::sMethod_replaceAll_0;
jmethodID StringProxy::sMethod_split_0;
jmethodID StringProxy::sMethod_split_1;
jmethodID StringProxy::sMethod_join_0;
jmethodID StringProxy::sMethod_join_1;
jmethodID StringProxy::sMethod_toLowerCase_0;
jmethodID StringProxy::sMethod_toLowerCase_1;
jmethodID StringProxy::sMethod_toUpperCase_0;
jmethodID StringProxy::sMethod_toUpperCase_1;
jmethodID StringProxy::sMethod_trim_0;
jmethodID StringProxy::sMethod_toString_0;
jmethodID StringProxy::sMethod_toCharArray_0;
jmethodID StringProxy::sMethod_format_0;
jmethodID StringProxy::sMethod_format_1;
jmethodID StringProxy::sMethod_valueOf_0;
jmethodID StringProxy::sMethod_valueOf_1;
jmethodID StringProxy::sMethod_valueOf_2;
jmethodID StringProxy::sMethod_valueOf_3;
jmethodID StringProxy::sMethod_valueOf_4;
jmethodID StringProxy::sMethod_valueOf_5;
jmethodID StringProxy::sMethod_valueOf_6;
jmethodID StringProxy::sMethod_valueOf_7;
jmethodID StringProxy::sMethod_valueOf_8;
jmethodID StringProxy::sMethod_copyValueOf_0;
jmethodID StringProxy::sMethod_copyValueOf_1;
jmethodID StringProxy::sMethod_intern_0;

jfieldID StringProxy::sField_CASE_INSENSITIVE_ORDER_0;

} // endof namespace java
