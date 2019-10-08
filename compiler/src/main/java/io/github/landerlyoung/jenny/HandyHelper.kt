/** * Copyright 2016 landerlyoung@gmail.com * * Licensed under the Apache License, Version 2.0 (the "License"); * you may not use this file except in compliance with the License. * You may obtain a copy of the License at * * http://www.apache.org/licenses/LICENSE-2.0 * * Unless required by applicable law or agreed to in writing, software * distributed under the License is distributed on an "AS IS" BASIS, * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. * See the License for the specific language governing permissions and * limitations under the License. */package io.github.landerlyoung.jennyimport java.util.*import javax.lang.model.element.*import javax.lang.model.type.ArrayTypeimport javax.lang.model.type.DeclaredTypeimport javax.lang.model.type.NoTypeimport javax.lang.model.type.TypeMirror/** * Author: landerlyoung@gmail.com * Date:   2014-12-17 * Time:   20:19 * Life with passion. Code with creativity! */class HandyHelper(private val mEnv: Environment) {    fun getMethodSignature(method: ExecutableElement): String {        return Signature(method, false).toString()    }    /**     *     * example     * Signature: (ILjava/lang/Runnable;LN/M_M;)V     * JNIEXPORT void JNICALL Java_N_n__ILjava_lang_Runnable_2LN_M_1M_2     *     * __ILjava_lang_Runnable_2LN_M_1M_2     */    fun getMethodOverloadPostfix(method: ExecutableElement): String {        val signature = getMethodSignature(method)        val paramSig = signature.subSequence(signature.indexOf('(') + 1, signature.indexOf(")")).toString()        return "__" + paramSig.replace("_", "_1")                .replace("/", "_")                .replace(";", "_2")    }    fun getTypeSignature(type: TypeMirror): String {        return Signature(type, false).toString()    }    fun getTypeSignatureOverloadPostfix(type: TypeMirror): String =            getTypeSignature(type).replace("_", "_1")                    .replace("/", "_")                    .replace(";", "_2")    // same as java, but do not change '$' to '/' for inner classes.    fun getBinaryMethodSignature(method: ExecutableElement): String {        return Signature(method, true).toString()    }    fun getBinaryTypeSignature(type: TypeMirror): String {        return Signature(type, true).toString()    }    /**     * @return like com.example_package.SomeClass$InnerClass     */    fun getClassName(clazz: Element): String {        val className = Stack<String>()        val sb = StringBuilder()        var e: Element? = clazz        while (e != null && (ElementKind.CLASS == e.kind || ElementKind.INTERFACE == e.kind)) {            className.push(e.simpleName.toString())            e = e.enclosingElement        }        val pkg = mEnv.elementUtils.getPackageOf(clazz)        if (pkg != null) {            val pkgName = pkg.qualifiedName.toString()            if (pkgName.isNotEmpty()) {                sb.append(pkgName)                sb.append('.')            }        }        while (!className.empty()) {            sb.append(className.pop())            sb.append('$')        }        sb.deleteCharAt(sb.length - 1)        return sb.toString()    }    /**     * @return like com/example_package/SomeClass$InnerClass     */    fun getSlashClassName(className: String): String {        return className.replace('.', '/')    }    /**     * @return like com_example_1package_SomeClass_InnerClass     */    fun getJNIClassName(c: Class<*>): String? {        return toJNIClassName(c.name)    }    /**     * @return eg. "String" for java.lang.String     */    fun getSimpleName(clazz: Element): String {        return clazz.simpleName.toString()    }    /**     * @param className     *     * @return like com_example_1package_SomeClass_InnerClass     */    fun toJNIClassName(className: String?): String? {        return className?.replace("_", "_1")                ?.replace(".", "_")                ?.replace("$", "_00024")    }    fun getModifiers(m: Element): String {        val sb = StringBuilder()        m.modifiers                .asSequence()                .filter { modifier ->                    (modifier == Modifier.PUBLIC                            || modifier == Modifier.PROTECTED                            || modifier == Modifier.PRIVATE                            || modifier == Modifier.FINAL                            || modifier == Modifier.STATIC                            || modifier == Modifier.ABSTRACT                            || modifier == Modifier.SYNCHRONIZED)                }                .sorted()                .forEach { modifier ->                    sb.append(modifier.toString().toLowerCase(Locale.US))                    sb.append(' ')                }        if (sb.isNotEmpty()) {            //delete the last space            sb.replace(sb.length - 1, sb.length, "")        }        return sb.toString()    }    fun getJavaMethodParam(m: ExecutableElement): String {        val sb = StringBuilder()        val it = m.parameters.iterator()        while (it.hasNext()) {            val v = it.next()            sb.append(v.asType().toString())                    .append(' ')                    .append(v.simpleName)            if (it.hasNext()) {                sb.append(", ")            }        }        return sb.toString()    }    fun getReturnStatement(e: ExecutableElement): String {        val sb = StringBuilder()        sb.append("return ")        val typeName = e.returnType.toString()        if (String::class.java.name == typeName) {            sb.append("env->NewStringUTF(\"Hello From Jenny\")")        } else if (Int::class.javaPrimitiveType!!.name == typeName                || Byte::class.javaPrimitiveType!!.name == typeName                || Char::class.javaPrimitiveType!!.name == typeName                || Short::class.javaPrimitiveType!!.name == typeName                || Long::class.javaPrimitiveType!!.name == typeName                || Float::class.javaPrimitiveType!!.name == typeName                || Double::class.javaPrimitiveType!!.name == typeName) {            sb.append("0")        } else if (Boolean::class.javaPrimitiveType!!.name == typeName) {            sb.append("JNI_FALSE")        } else if (Void.TYPE.name == typeName) {            //eat that space            sb.replace(sb.length - 1, sb.length, "")        } else {            sb.append("nullptr")        }        sb.append(";")        return sb.toString()    }    fun getNativeMethodParam(m: ExecutableElement): String {        val sb = StringBuilder()        sb.append("JNIEnv *env")        if (m.modifiers.contains(Modifier.STATIC)) {            sb.append(", jclass clazz")        } else {            sb.append(", jobject thiz")        }        m.parameters.forEach { ve ->            sb.append(", ")            sb.append(toJNIType(ve.asType()))            sb.append(' ')            sb.append(ve.simpleName.toString())        }        return sb.toString()    }    private fun instanceOf(clazz: Class<*>, typeMirror: TypeMirror): Boolean {        var t = typeMirror        val clazzName = clazz.name        while (clazzName != getNonGenericName(t)) {            val base = mEnv.typeUtils.asElement(t)            if (base is TypeElement) {                val superClazz = base.superclass                if (superClazz is NoType) return false                t = superClazz            } else {                return false            }        }        return true    }    fun getNonGenericName(t: TypeMirror): String {        return t.toString().replace("<.*>".toRegex(), "")    }    fun toJNIType(t: TypeMirror?): String {        if (t == null) return ""        //check if t is a subclass of java.lang.Throwable        if (instanceOf(Throwable::class.java, t)) {            return "jthrowable"        }        //remove generic        when (val c = getNonGenericName(t)) {            //void type            "void" -> return "void"            //primitive type            "char", "boolean", "byte", "short", "int", "long", "float", "double" -> return "j$c"            //array type            "char[]", "boolean[]", "byte[]", "short[]", "int[]", "long[]", "float[]", "double[]" -> return 'j'.toString() + c.substring(0, c.length - 2) + "Array"            //native build in type            "java.lang.String" -> return "jstring"            "java.lang.Class" -> return "jclass"            else -> return if (c.endsWith("[]")) {                //java.lang.Object[]                "jobjectArray"            } else {                "jobject"            }        }    }    fun toNativeType(t: TypeMirror?, useAutoType: Boolean): String? {        return if (t == null) null else toNativeType(getNonGenericName(t), useAutoType)    }    fun toNativeType(className: String, useAutoType: Boolean): String? {        return when (className) {            //void type            "void" -> "void"            //primitive type            "short", "int", "long", "float", "double", "char", "boolean", "byte" -> "j$className"            "java.lang.String" -> if (useAutoType) {                "auto"            } else {                "char *"            }            else -> null        }    }    fun isNestedClass(clazz: Element): Boolean {        val enclosingElement: Element? = clazz.enclosingElement        return (enclosingElement != null                && enclosingElement.kind == ElementKind.CLASS                && !clazz.modifiers.contains(Modifier.STATIC))    }    private inner class Signature private constructor(private val mMethod: ExecutableElement?, private val mType: TypeMirror?, private val mIsNative: Boolean) {        private val mCache: StringBuilder = StringBuilder()        // same as java        private//constructor        // generate this$0 param for nested class        val methodSignature: String            get() {                mCache.append('(')                if (mMethod!!.simpleName.contentEquals("<init>")) {                    val clazz = mMethod.enclosingElement                    if (isNestedClass(clazz)) {                        val enclosingClazz = clazz.enclosingElement                        getSignatureClassName(enclosingClazz.asType())                    }                }                for (param in mMethod.parameters) {                    getSignatureClassName(param.asType())                }                mCache.append(')')                getSignatureClassName(mMethod.returnType)                return mCache.toString()            }        constructor(method: ExecutableElement, isNative: Boolean) : this(method, null, isNative)        constructor(type: TypeMirror, isNative: Boolean) : this(null, type, isNative)        private fun getSignatureClassName(_type: TypeMirror?) {            var type = _type            while (type is ArrayType) {                mCache.append('[')                type = type.componentType            }            val className: String            className = if (type is DeclaredType) {                getClassName(type.asElement())            } else {                getNonGenericName(type!!)            }            getObjectSignatureClassName(className)        }        private fun getObjectSignatureClassName(type: String) {            if ("char" == type) {                mCache.append('C')            } else if ("byte" == type) {                mCache.append('B')            } else if ("short" == type) {                mCache.append('S')            } else if ("int" == type) {                mCache.append('I')            } else if ("long" == type) {                mCache.append('J')            } else if ("float" == type) {                mCache.append('F')            } else if ("double" == type) {                mCache.append('D')            } else if ("boolean" == type) {                mCache.append('Z')            } else if ("void" == type) {                mCache.append('V')            } else {                if (mIsNative) {                    mCache.append('L').append(type.replace('.', '/')).append(';')                } else {                    mCache.append('L')                            .append(type.replace('.', '/').replace('$', '/'))                            .append(';')                }            }        }        override fun toString(): String {            return if (mMethod != null) {                methodSignature            } else {                getSignatureClassName(mType)                mCache.toString()            }        }    }    companion object {        /**         * @param v         *         * @return         */        fun getJNIHeaderConstantValue(v: Any?): String {            if (v == null) {                return ""            }            return if (v is Boolean) {                if (v) "JNI_TRUE" else "JNI_FALSE"            } else if (v is Number || v is Char) {                v.toString() + ""            } else if (v is String) {                "\"" + v + "\""            } else {                throw IllegalArgumentException("unknown type:$v " + v.javaClass)            }        }    }}