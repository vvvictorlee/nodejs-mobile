//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

struct JsAPIHooks
{
    typedef JsErrorCode (WINAPI *JsrtCreateRuntimePtr)(JsRuntimeAttributes attributes, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime);
    typedef JsErrorCode (WINAPI *JsrtCreateContextPtr)(JsRuntimeHandle runtime, JsContextRef *newContext);
    typedef JsErrorCode (WINAPI *JsrtSetRuntimeMemoryLimitPtr)(JsRuntimeHandle runtime, size_t memoryLimit);
    typedef JsErrorCode (WINAPI *JsrtSetCurrentContextPtr)(JsContextRef context);
    typedef JsErrorCode (WINAPI *JsrtGetCurrentContextPtr)(JsContextRef* context);
    typedef JsErrorCode (WINAPI *JsrtDisposeRuntimePtr)(JsRuntimeHandle runtime);
    typedef JsErrorCode (WINAPI *JsrtCreateObjectPtr)(JsValueRef *object);
    typedef JsErrorCode (WINAPI *JsrtCreateExternalObjectPtr)(void* data, JsFinalizeCallback callback, JsValueRef *object);
    typedef JsErrorCode (WINAPI *JsrtCreateFunctionPtr)(JsNativeFunction nativeFunction, void *callbackState, JsValueRef *function);
    typedef JsErrorCode (WINAPI *JsCreateNamedFunctionPtr)(JsValueRef name, JsNativeFunction nativeFunction, void *callbackState, JsValueRef *function);
    typedef JsErrorCode (WINAPI *JsrtPointerToStringUtf8Ptr)(const char *stringValue, size_t length, JsValueRef *value);
    typedef JsErrorCode (WINAPI *JsrtSetPropertyPtr)(JsValueRef object, JsPropertyIdRef property, JsValueRef value, bool useStrictRules);
    typedef JsErrorCode (WINAPI *JsrtGetGlobalObjectPtr)(JsValueRef *globalObject);
    typedef JsErrorCode (WINAPI *JsrtGetUndefinedValuePtr)(JsValueRef *globalObject);
    typedef JsErrorCode (WINAPI *JsrtConvertValueToStringPtr)(JsValueRef value, JsValueRef *stringValue);
    typedef JsErrorCode (WINAPI *JsrtConvertValueToNumberPtr)(JsValueRef value, JsValueRef *numberValue);
    typedef JsErrorCode (WINAPI *JsrtConvertValueToBooleanPtr)(JsValueRef value, JsValueRef *booleanValue);
    typedef JsErrorCode (WINAPI *JsrtStringToPointerUtf8CopyPtr)(JsValueRef value, char **stringValue, size_t *length);
    typedef JsErrorCode (WINAPI *JsrtBooleanToBoolPtr)(JsValueRef value, bool *boolValue);
    typedef JsErrorCode (WINAPI *JsrtGetPropertyIdFromNameUtf8Ptr)(const char *name, JsPropertyIdRef *propertyId);
    typedef JsErrorCode (WINAPI *JsrtGetPropertyPtr)(JsValueRef object, JsPropertyIdRef property, JsValueRef* value);
    typedef JsErrorCode (WINAPI *JsrtHasPropertyPtr)(JsValueRef object, JsPropertyIdRef property, bool *hasProperty);
    typedef JsErrorCode (WINAPI *JsrtCallFunctionPtr)(JsValueRef function, JsValueRef* arguments, unsigned short argumentCount, JsValueRef *result);
    typedef JsErrorCode (WINAPI *JsrtNumberToDoublePtr)(JsValueRef value, double *doubleValue);
    typedef JsErrorCode (WINAPI *JsrtNumberToIntPtr)(JsValueRef value, int *intValue);
    typedef JsErrorCode (WINAPI *JsrtDoubleToNumberPtr)(double doubleValue, JsValueRef* value);
    typedef JsErrorCode (WINAPI *JsrtGetExternalDataPtr)(JsValueRef object, void **data);
    typedef JsErrorCode (WINAPI *JsrtCreateArrayPtr)(unsigned int length, JsValueRef *result);
    typedef JsErrorCode (WINAPI *JsrtCreateErrorPtr)(JsValueRef message, JsValueRef *error);
    typedef JsErrorCode(WINAPI *JsrtHasExceptionPtr)(bool *hasException);
    typedef JsErrorCode (WINAPI *JsrtSetExceptionPtr)(JsValueRef exception);
    typedef JsErrorCode (WINAPI *JsrtGetAndClearExceptiopnPtr)(JsValueRef* exception);
    typedef JsErrorCode (WINAPI *JsrtGetRuntimePtr)(JsContextRef context, JsRuntimeHandle *runtime);
    typedef JsErrorCode (WINAPI *JsrtReleasePtr)(JsRef ref, unsigned int* count);
    typedef JsErrorCode (WINAPI *JsrtAddRefPtr)(JsRef ref, unsigned int* count);
    typedef JsErrorCode (WINAPI *JsrtGetValueType)(JsValueRef value, JsValueType *type);
    typedef JsErrorCode (WINAPI *JsrtSetIndexedPropertyPtr)(JsValueRef object, JsValueRef index, JsValueRef value);
    typedef JsErrorCode (WINAPI *JsrtSetPromiseContinuationCallbackPtr)(JsPromiseContinuationCallback callback, void *callbackState);
    typedef JsErrorCode (WINAPI *JsrtGetContextOfObject)(JsValueRef object, JsContextRef *callbackState);

    typedef JsErrorCode(WINAPI *JsrtParseScriptWithAttributesUtf8)(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsParseScriptAttributes parseAttributes, JsValueRef *result);
    typedef JsErrorCode(WINAPI *JsrtDiagStartDebugging)(JsRuntimeHandle runtimeHandle, JsDiagDebugEventCallback debugEventCallback, void* callbackState);
    typedef JsErrorCode(WINAPI *JsrtDiagStopDebugging)(JsRuntimeHandle runtimeHandle, void** callbackState);
    typedef JsErrorCode(WINAPI *JsrtDiagGetSource)(unsigned int scriptId, JsValueRef *source);
    typedef JsErrorCode(WINAPI *JsrtDiagSetBreakpoint)(unsigned int scriptId, unsigned int lineNumber, unsigned int columnNumber, JsValueRef *breakPoint);
    typedef JsErrorCode(WINAPI *JsrtDiagGetStackTrace)(JsValueRef *stackTrace);
    typedef JsErrorCode(WINAPI *JsrtDiagRequestAsyncBreak)(JsRuntimeHandle runtimeHandle);
    typedef JsErrorCode(WINAPI *JsrtDiagGetBreakpoints)(JsValueRef * breakpoints);
    typedef JsErrorCode(WINAPI *JsrtDiagRemoveBreakpoint)(unsigned int breakpointId);
    typedef JsErrorCode(WINAPI *JsrtDiagSetBreakOnException)(JsRuntimeHandle runtimeHandle, JsDiagBreakOnExceptionAttributes exceptionAttributes);
    typedef JsErrorCode(WINAPI *JsrtDiagGetBreakOnException)(JsRuntimeHandle runtimeHandle, JsDiagBreakOnExceptionAttributes * exceptionAttributes);
    typedef JsErrorCode(WINAPI *JsrtDiagSetStepType)(JsDiagStepType stepType);
    typedef JsErrorCode(WINAPI *JsrtDiagGetScripts)(JsValueRef * scriptsArray);
    typedef JsErrorCode(WINAPI *JsrtDiagGetFunctionPosition)(JsValueRef value, JsValueRef * functionInfo);
    typedef JsErrorCode(WINAPI *JsrtDiagGetStackProperties)(unsigned int stackFrameIndex, JsValueRef * properties);
    typedef JsErrorCode(WINAPI *JsrtDiagGetProperties)(unsigned int objectHandle, unsigned int fromCount, unsigned int totalCount, JsValueRef * propertiesObject);
    typedef JsErrorCode(WINAPI *JsrtDiagGetObjectFromHandle)(unsigned int handle, JsValueRef * handleObject);
    typedef JsErrorCode(WINAPI *JsrtDiagEvaluateUtf8)(const char * expression, unsigned int stackFrameIndex, JsValueRef * evalResult);

    typedef JsErrorCode(WINAPI *JsrtRunScriptUtf8)(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef *result);
    typedef JsErrorCode(WINAPI *JsrtSerializeScriptUtf8)(const char *script, ChakraBytePtr buffer, unsigned int *bufferSize);
    typedef JsErrorCode(WINAPI *JsrtRunSerializedScriptUtf8)(JsSerializedScriptLoadUtf8SourceCallback scriptLoadCallback, JsSerializedScriptUnloadCallback scriptUnloadCallback, ChakraBytePtr buffer, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef * result);
    typedef JsErrorCode(WINAPI *JsrtRunModuleUtf8Ptr)(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef *result);
    typedef JsErrorCode(WINAPI *JsrtStringFreePtr)(const char *stringValue);

    typedef JsErrorCode(WINAPI *JsrtTTDCreateRecordRuntimePtr)(JsRuntimeAttributes attributes, char* infoUri, size_t infoUriCount, UINT32 snapInterval, UINT32 snapHistoryLength, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime);
    typedef JsErrorCode(WINAPI *JsrtTTDCreateDebugRuntimePtr)(JsRuntimeAttributes attributes, char* infoUri, size_t infoUriCount, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime);
    typedef JsErrorCode(WINAPI *JsrtTTDCreateContextPtr)(JsRuntimeHandle runtime, JsContextRef *newContext);
    typedef JsErrorCode(WINAPI *JsrtTTDRunScriptPtr)(INT64 hostCallbackId, const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef* result);
    typedef JsErrorCode(WINAPI *JsrtTTDCallFunctionPtr)(INT64 hostCallbackId, JsValueRef function, JsValueRef* arguments, unsigned short argumentCount, JsValueRef *result);

    typedef JsErrorCode(WINAPI *JsrtTTDSetIOCallbacksPtr)(JsRuntimeHandle runtime, JsTTDInitializeUriCallback ttdInitializeTTDUriFunction, JsTTDInitializeForWriteLogStreamCallback writeInitializeFunction, JsTTDGetLogStreamCallback getLogStreamInfo, JsTTDGetSnapshotStreamCallback getSnapshotStreamInfo, JsTTDGetSrcCodeStreamCallback getSrcCodeStreamInfo, JsTTDReadBytesFromStreamCallback readBytesFromStream, JsTTDWriteBytesToStreamCallback writeBytesToStream, JsTTDFlushAndCloseStreamCallback flushAndCloseStream);

    typedef JsErrorCode(WINAPI *JsrtTTDStartTimeTravelRecordingPtr)();
    typedef JsErrorCode(WINAPI *JsrtTTDStopTimeTravelRecordingPtr)();
    typedef JsErrorCode(WINAPI *JsrtTTDEmitTimeTravelRecordingPtr)();
    typedef JsErrorCode(WINAPI *JsrtTTDStartTimeTravelDebuggingPtr)();
    typedef JsErrorCode(WINAPI *JsrtTTDPauseTimeTravelBeforeRuntimeOperationPtr)();
    typedef JsErrorCode(WINAPI *JsrtTTDReStartTimeTravelAfterRuntimeOperationPtr)();

    typedef JsErrorCode(WINAPI *JsrtTTDNotifyHostCallbackCreatedOrCanceledPtr)(bool isCreate, bool isCancel, bool isRepeating, JsValueRef function, INT64 callbackId);
    typedef JsErrorCode(WINAPI *JsrtTTDNotifyYieldPtr)();

    typedef JsErrorCode(WINAPI *JsrtTTDPrepContextsForTopLevelEventMovePtr)(JsRuntimeHandle runtimeHandle, INT64 targetEventTime, INT64* targetStartSnapTime);
    typedef JsErrorCode(WINAPI *JsrtTTDMoveToTopLevelEventPtr)(INT64 snapshotStartTime, INT64 eventTime);
    typedef JsErrorCode(WINAPI *JsrtTTDReplayExecutionPtr)(INT64* rootEventTime);

    JsrtCreateRuntimePtr pfJsrtCreateRuntime;
    JsrtCreateContextPtr pfJsrtCreateContext;
    JsrtSetRuntimeMemoryLimitPtr pfJsrtSetRuntimeMemoryLimit;
    JsrtSetCurrentContextPtr pfJsrtSetCurrentContext;
    JsrtGetCurrentContextPtr pfJsrtGetCurrentContext;
    JsrtDisposeRuntimePtr pfJsrtDisposeRuntime;
    JsrtCreateObjectPtr pfJsrtCreateObject;
    JsrtCreateExternalObjectPtr pfJsrtCreateExternalObject;
    JsrtCreateFunctionPtr pfJsrtCreateFunction;
    JsCreateNamedFunctionPtr pfJsrtCreateNamedFunction;
    JsrtPointerToStringUtf8Ptr pfJsrtPointerToStringUtf8;
    JsrtSetPropertyPtr pfJsrtSetProperty;
    JsrtGetGlobalObjectPtr pfJsrtGetGlobalObject;
    JsrtGetUndefinedValuePtr pfJsrtGetUndefinedValue;
    JsrtGetUndefinedValuePtr pfJsrtGetTrueValue;
    JsrtGetUndefinedValuePtr pfJsrtGetFalseValue;
    JsrtConvertValueToStringPtr pfJsrtConvertValueToString;
    JsrtConvertValueToNumberPtr pfJsrtConvertValueToNumber;
    JsrtConvertValueToBooleanPtr pfJsrtConvertValueToBoolean;
    JsrtStringToPointerUtf8CopyPtr pfJsrtStringToPointerUtf8Copy;
    JsrtBooleanToBoolPtr pfJsrtBooleanToBool;
    JsrtGetPropertyIdFromNameUtf8Ptr pfJsrtGetPropertyIdFromNameUtf8;
    JsrtGetPropertyPtr pfJsrtGetProperty;
    JsrtHasPropertyPtr pfJsrtHasProperty;
    JsrtCallFunctionPtr pfJsrtCallFunction;
    JsrtNumberToDoublePtr pfJsrtNumberToDouble;
    JsrtNumberToIntPtr pfJsrtNumberToInt;
    JsrtDoubleToNumberPtr pfJsrtDoubleToNumber;
    JsrtGetExternalDataPtr pfJsrtGetExternalData;
    JsrtCreateArrayPtr pfJsrtCreateArray;
    JsrtCreateErrorPtr pfJsrtCreateError;
    JsrtHasExceptionPtr pfJsrtHasException;
    JsrtSetExceptionPtr pfJsrtSetException;
    JsrtGetAndClearExceptiopnPtr pfJsrtGetAndClearException;
    JsrtGetRuntimePtr pfJsrtGetRuntime;
    JsrtReleasePtr pfJsrtRelease;
    JsrtAddRefPtr pfJsrtAddRef;
    JsrtGetValueType pfJsrtGetValueType;
    JsrtSetIndexedPropertyPtr pfJsrtSetIndexedProperty;
    JsrtSetPromiseContinuationCallbackPtr pfJsrtSetPromiseContinuationCallback;
    JsrtGetContextOfObject pfJsrtGetContextOfObject;
    JsrtParseScriptWithAttributesUtf8 pfJsrtParseScriptWithAttributesUtf8;
    JsrtDiagStartDebugging pfJsrtDiagStartDebugging;
    JsrtDiagStopDebugging pfJsrtDiagStopDebugging;
    JsrtDiagGetSource pfJsrtDiagGetSource;
    JsrtDiagSetBreakpoint pfJsrtDiagSetBreakpoint;
    JsrtDiagGetStackTrace pfJsrtDiagGetStackTrace;
    JsrtDiagRequestAsyncBreak pfJsrtDiagRequestAsyncBreak;
    JsrtDiagGetBreakpoints pfJsrtDiagGetBreakpoints;
    JsrtDiagRemoveBreakpoint pfJsrtDiagRemoveBreakpoint;
    JsrtDiagSetBreakOnException pfJsrtDiagSetBreakOnException;
    JsrtDiagGetBreakOnException pfJsrtDiagGetBreakOnException;
    JsrtDiagSetStepType pfJsrtDiagSetStepType;
    JsrtDiagGetScripts pfJsrtDiagGetScripts;
    JsrtDiagGetFunctionPosition pfJsrtDiagGetFunctionPosition;
    JsrtDiagGetStackProperties pfJsrtDiagGetStackProperties;
    JsrtDiagGetProperties pfJsrtDiagGetProperties;
    JsrtDiagGetObjectFromHandle pfJsrtDiagGetObjectFromHandle;
    JsrtDiagEvaluateUtf8 pfJsrtDiagEvaluateUtf8;

    JsrtRunScriptUtf8 pfJsrtRunScriptUtf8;
    JsrtSerializeScriptUtf8 pfJsrtSerializeScriptUtf8;
    JsrtRunSerializedScriptUtf8 pfJsrtRunSerializedScriptUtf8;
    JsrtRunModuleUtf8Ptr pfJsrtExperimentalApiRunModuleUtf8;
    JsrtStringFreePtr pfJsrtStringFree;

    JsrtTTDCreateRecordRuntimePtr pfJsrtTTDCreateRecordRuntime;
    JsrtTTDCreateDebugRuntimePtr pfJsrtTTDCreateDebugRuntime;
    JsrtTTDCreateContextPtr pfJsrtTTDCreateContext;
    JsrtTTDRunScriptPtr pfJsrtTTDRunScript;
    JsrtTTDCallFunctionPtr pfJsrtTTDCallFunction;

    JsrtTTDSetIOCallbacksPtr pfJsrtTTDSetIOCallbacks;

    JsrtTTDStartTimeTravelRecordingPtr pfJsrtTTDStartTimeTravelRecording;
    JsrtTTDStopTimeTravelRecordingPtr pfJsrtTTDStopTimeTravelRecording;
    JsrtTTDEmitTimeTravelRecordingPtr pfJsrtTTDEmitTimeTravelRecording;
    JsrtTTDStartTimeTravelDebuggingPtr pfJsrtTTDStartTimeTravelDebugging;
    JsrtTTDPauseTimeTravelBeforeRuntimeOperationPtr pfJsrtTTDPauseTimeTravelBeforeRuntimeOperation;
    JsrtTTDReStartTimeTravelAfterRuntimeOperationPtr pfJsrtTTDReStartTimeTravelAfterRuntimeOperation;

    JsrtTTDNotifyHostCallbackCreatedOrCanceledPtr pfJsrtTTDNotifyHostCallbackCreatedOrCanceled;
    JsrtTTDNotifyYieldPtr pfJsrtTTDNotifyYield;

    JsrtTTDPrepContextsForTopLevelEventMovePtr pfJsrtTTDPrepContextsForTopLevelEventMove;
    JsrtTTDMoveToTopLevelEventPtr pfJsrtTTDMoveToTopLevelEvent;
    JsrtTTDReplayExecutionPtr pfJsrtTTDReplayExecution;
};

class ChakraRTInterface
{
public:
    typedef void(__stdcall * HostPrintUsageFuncPtr)();

    struct ArgInfo
    {
        int argc;
        LPWSTR* argv;
        HostPrintUsageFuncPtr hostPrintUsage;
        char* filename;

        ~ArgInfo()
        {
            if (filename != nullptr)
            {
                free(filename);
            }
        }
    };

#define CHECKED_CALL_RETURN(func, retVal, ...) (m_testHooksSetup && m_testHooks.pf##func? m_testHooks.pf##func(__VA_ARGS__) : retVal)
#define CHECKED_CALL(func, ...) (m_testHooksSetup && m_testHooks.pf##func? m_testHooks.pf##func(__VA_ARGS__) : E_NOTIMPL)

private:
    static bool m_testHooksSetup;
    static bool m_testHooksInitialized;
    static bool m_usageStringPrinted;
    static ArgInfo* m_argInfo;
    static TestHooks m_testHooks;
    static JsAPIHooks m_jsApiHooks;

private:
    static HRESULT ParseConfigFlags();

public:
    static HRESULT OnChakraCoreLoaded(TestHooks& testHooks);

    static bool LoadChakraDll(ArgInfo* argInfo, HINSTANCE *library);
    static void UnloadChakraDll(HINSTANCE library);

    static HRESULT SetAssertToConsoleFlag(bool flag) { return CHECKED_CALL(SetAssertToConsoleFlag, flag); }
    static HRESULT SetConfigFlags(__in int argc, __in_ecount(argc) LPWSTR argv[], ICustomConfigFlags* customConfigFlags) { return CHECKED_CALL(SetConfigFlags, argc, argv, customConfigFlags); }
    static HRESULT GetFileNameFlag(BSTR * filename) { return CHECKED_CALL(GetFilenameFlag, filename); }
    static HRESULT PrintConfigFlagsUsageString() { m_usageStringPrinted = true;  return CHECKED_CALL(PrintConfigFlagsUsageString); }

#ifdef CHECK_MEMORY_LEAK
    static bool IsEnabledCheckMemoryFlag() { return CHECKED_CALL_RETURN(IsEnabledCheckMemoryLeakFlag, FALSE); }
    static HRESULT SetCheckMemoryLeakFlag(bool flag) { return CHECKED_CALL(SetCheckMemoryLeakFlag, flag); }
    static HRESULT SetEnableCheckMemoryLeakOutput(bool flag) { return CHECKED_CALL(SetEnableCheckMemoryLeakOutput, flag); }
#endif
#ifdef DEBUG
    static HRESULT SetCheckOpHelpersFlag(bool flag) { return CHECKED_CALL(SetCheckOpHelpersFlag, flag); }
#endif

    static HRESULT GetCrashOnExceptionFlag(bool * flag)
    {
#ifdef SECURITY_TESTING
        return CHECKED_CALL(GetCrashOnExceptionFlag, flag);
#else
        return E_UNEXPECTED;
#endif
    }

    static void NotifyUnhandledException(PEXCEPTION_POINTERS exceptionInfo)
    {
        if (m_testHooksSetup && m_testHooks.pfnNotifyUnhandledException != NULL)
        {
            m_testHooks.pfnNotifyUnhandledException(exceptionInfo);
        }
    }
#ifdef CHAKRA_STATIC_LIBRARY
#define HOOK_JS_API(x) ::Js##x
#else
#define HOOK_JS_API(x) m_jsApiHooks.pfJsrt##x
#endif

    static JsErrorCode WINAPI JsCreateRuntime(JsRuntimeAttributes attributes, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime) { return HOOK_JS_API(CreateRuntime(attributes, threadService, runtime)); }
    static JsErrorCode WINAPI JsCreateContext(JsRuntimeHandle runtime, JsContextRef *newContext) { return HOOK_JS_API(CreateContext(runtime, newContext)); }
    static JsErrorCode WINAPI JsSetRuntimeMemoryLimit(JsRuntimeHandle runtime, size_t memory) { return HOOK_JS_API(SetRuntimeMemoryLimit(runtime, memory)); }
    static JsErrorCode WINAPI JsSetCurrentContext(JsContextRef context) { return HOOK_JS_API(SetCurrentContext(context)); }
    static JsErrorCode WINAPI JsGetCurrentContext(JsContextRef* context) { return HOOK_JS_API(GetCurrentContext(context)); }
    static JsErrorCode WINAPI JsDisposeRuntime(JsRuntimeHandle runtime) { return HOOK_JS_API(DisposeRuntime(runtime)); }
    static JsErrorCode WINAPI JsCreateObject(JsValueRef *object) { return HOOK_JS_API(CreateObject(object)); }
    static JsErrorCode WINAPI JsCreateExternalObject(void *data, JsFinalizeCallback callback, JsValueRef *object) { return HOOK_JS_API(CreateExternalObject(data, callback, object)); }
    static JsErrorCode WINAPI JsCreateFunction(JsNativeFunction nativeFunction, void *callbackState, JsValueRef *function) { return HOOK_JS_API(CreateFunction(nativeFunction, callbackState, function)); }
    static JsErrorCode WINAPI JsCreateNamedFunction(JsValueRef name, JsNativeFunction nativeFunction, void *callbackState, JsValueRef *function) { return HOOK_JS_API(CreateNamedFunction(name, nativeFunction, callbackState, function)); }
    static JsErrorCode WINAPI JsSetProperty(JsValueRef object, JsPropertyIdRef property, JsValueRef value, bool useStrictRules) { return HOOK_JS_API(SetProperty(object, property, value, useStrictRules)); }
    static JsErrorCode WINAPI JsGetGlobalObject(JsValueRef *globalObject) { return HOOK_JS_API(GetGlobalObject(globalObject)); }
    static JsErrorCode WINAPI JsGetUndefinedValue(JsValueRef *globalObject) { return HOOK_JS_API(GetUndefinedValue(globalObject)); }
    static JsErrorCode WINAPI JsGetTrueValue(JsValueRef *globalObject) { return HOOK_JS_API(GetTrueValue(globalObject)); }
    static JsErrorCode WINAPI JsGetFalseValue(JsValueRef *globalObject) { return HOOK_JS_API(GetFalseValue(globalObject)); }
    static JsErrorCode WINAPI JsConvertValueToString(JsValueRef value, JsValueRef *stringValue) { return HOOK_JS_API(ConvertValueToString(value, stringValue)); }
    static JsErrorCode WINAPI JsConvertValueToNumber(JsValueRef value, JsValueRef *numberValue) { return HOOK_JS_API(ConvertValueToNumber(value, numberValue)); }
    static JsErrorCode WINAPI JsConvertValueToBoolean(JsValueRef value, JsValueRef *booleanValue) { return HOOK_JS_API(ConvertValueToBoolean(value, booleanValue)); }
    static JsErrorCode WINAPI JsStringToPointerUtf8Copy(JsValueRef value, char **stringValue, size_t *length) { return HOOK_JS_API(StringToPointerUtf8Copy(value, stringValue, length)); }
    static JsErrorCode WINAPI JsBooleanToBool(JsValueRef value, bool* boolValue) { return HOOK_JS_API(BooleanToBool(value, boolValue)); }
    static JsErrorCode WINAPI JsGetPropertyIdFromNameUtf8(const char *name, JsPropertyIdRef *propertyId) { return HOOK_JS_API(GetPropertyIdFromNameUtf8(name, propertyId)); }
    static JsErrorCode WINAPI JsGetProperty(JsValueRef object, JsPropertyIdRef property, JsValueRef* value) { return HOOK_JS_API(GetProperty(object, property, value)); }
    static JsErrorCode WINAPI JsHasProperty(JsValueRef object, JsPropertyIdRef property, bool *hasProperty) { return HOOK_JS_API(HasProperty(object, property, hasProperty)); }
    static JsErrorCode WINAPI JsCallFunction(JsValueRef function, JsValueRef* arguments, unsigned short argumentCount, JsValueRef *result) { return HOOK_JS_API(CallFunction(function, arguments, argumentCount, result)); }
    static JsErrorCode WINAPI JsNumberToDouble(JsValueRef value, double* doubleValue) { return HOOK_JS_API(NumberToDouble(value, doubleValue)); }
    static JsErrorCode WINAPI JsNumberToInt(JsValueRef value, int* intValue) { return HOOK_JS_API(NumberToInt(value, intValue)); }
    static JsErrorCode WINAPI JsDoubleToNumber(double doubleValue, JsValueRef* value) { return HOOK_JS_API(DoubleToNumber(doubleValue, value)); }
    static JsErrorCode WINAPI JsGetExternalData(JsValueRef object, void **data) { return HOOK_JS_API(GetExternalData(object, data)); }
    static JsErrorCode WINAPI JsCreateArray(unsigned int length, JsValueRef *result) { return HOOK_JS_API(CreateArray(length, result)); }
    static JsErrorCode WINAPI JsCreateError(JsValueRef message, JsValueRef *error) { return HOOK_JS_API(CreateError(message, error)); }
    static JsErrorCode WINAPI JsHasException(bool *hasException) { return HOOK_JS_API(HasException(hasException)); }
    static JsErrorCode WINAPI JsSetException(JsValueRef exception) { return HOOK_JS_API(SetException(exception)); }
    static JsErrorCode WINAPI JsGetAndClearException(JsValueRef *exception) { return HOOK_JS_API(GetAndClearException(exception)); }
    static JsErrorCode WINAPI JsGetRuntime(JsContextRef context, JsRuntimeHandle *runtime) { return HOOK_JS_API(GetRuntime(context, runtime)); }
    static JsErrorCode WINAPI JsRelease(JsRef ref, unsigned int* count) { return HOOK_JS_API(Release(ref, count)); }
    static JsErrorCode WINAPI JsAddRef(JsRef ref, unsigned int* count) { return HOOK_JS_API(AddRef(ref, count)); }
    static JsErrorCode WINAPI JsGetValueType(JsValueRef value, JsValueType *type) { return HOOK_JS_API(GetValueType(value, type)); }
    static JsErrorCode WINAPI JsSetIndexedProperty(JsValueRef object, JsValueRef index, JsValueRef value) { return HOOK_JS_API(SetIndexedProperty(object, index, value)); }
    static JsErrorCode WINAPI JsSetPromiseContinuationCallback(JsPromiseContinuationCallback callback, void *callbackState) { return HOOK_JS_API(SetPromiseContinuationCallback(callback, callbackState)); }
    static JsErrorCode WINAPI JsGetContextOfObject(JsValueRef object, JsContextRef* context) { return HOOK_JS_API(GetContextOfObject(object, context)); }
    static JsErrorCode WINAPI JsParseScriptWithAttributesUtf8(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsParseScriptAttributes parseAttributes, JsValueRef *result) { return HOOK_JS_API(ParseScriptWithAttributesUtf8(script, sourceContext, sourceUrl, parseAttributes, result)); }
    static JsErrorCode WINAPI JsDiagStartDebugging(JsRuntimeHandle runtimeHandle, JsDiagDebugEventCallback debugEventCallback, void* callbackState) { return HOOK_JS_API(DiagStartDebugging(runtimeHandle, debugEventCallback, callbackState)); }
    static JsErrorCode WINAPI JsDiagStopDebugging(JsRuntimeHandle runtimeHandle, void** callbackState) { return HOOK_JS_API(DiagStopDebugging(runtimeHandle, callbackState)); }
    static JsErrorCode WINAPI JsDiagGetSource(unsigned int scriptId, JsValueRef *source) { return HOOK_JS_API(DiagGetSource(scriptId, source)); }
    static JsErrorCode WINAPI JsDiagSetBreakpoint(unsigned int scriptId, unsigned int lineNumber, unsigned int columnNumber, JsValueRef *breakpoint) { return HOOK_JS_API(DiagSetBreakpoint(scriptId, lineNumber, columnNumber, breakpoint)); }
    static JsErrorCode WINAPI JsDiagGetStackTrace(JsValueRef *stackTrace) { return HOOK_JS_API(DiagGetStackTrace(stackTrace)); }
    static JsErrorCode WINAPI JsDiagRequestAsyncBreak(JsRuntimeHandle runtimeHandle) { return HOOK_JS_API(DiagRequestAsyncBreak(runtimeHandle)); }
    static JsErrorCode WINAPI JsDiagGetBreakpoints(JsValueRef * breakpoints) { return HOOK_JS_API(DiagGetBreakpoints(breakpoints)); }
    static JsErrorCode WINAPI JsDiagRemoveBreakpoint(unsigned int breakpointId) { return HOOK_JS_API(DiagRemoveBreakpoint(breakpointId)); }
    static JsErrorCode WINAPI JsDiagSetBreakOnException(JsRuntimeHandle runtimeHandle, JsDiagBreakOnExceptionAttributes exceptionAttributes) { return HOOK_JS_API(DiagSetBreakOnException(runtimeHandle, exceptionAttributes)); }
    static JsErrorCode WINAPI JsDiagGetBreakOnException(JsRuntimeHandle runtimeHandle, JsDiagBreakOnExceptionAttributes * exceptionAttributes) { return HOOK_JS_API(DiagGetBreakOnException(runtimeHandle, exceptionAttributes)); }
    static JsErrorCode WINAPI JsDiagSetStepType(JsDiagStepType stepType) { return HOOK_JS_API(DiagSetStepType(stepType)); }
    static JsErrorCode WINAPI JsDiagGetScripts(JsValueRef * scriptsArray) { return HOOK_JS_API(DiagGetScripts(scriptsArray)); }
    static JsErrorCode WINAPI JsDiagGetFunctionPosition(JsValueRef value, JsValueRef * functionPosition) { return HOOK_JS_API(DiagGetFunctionPosition(value, functionPosition)); }
    static JsErrorCode WINAPI JsDiagGetStackProperties(unsigned int stackFrameIndex, JsValueRef * properties) { return HOOK_JS_API(DiagGetStackProperties(stackFrameIndex, properties)); }
    static JsErrorCode WINAPI JsDiagGetProperties(unsigned int objectHandle, unsigned int fromCount, unsigned int totalCount, JsValueRef * propertiesObject) { return HOOK_JS_API(DiagGetProperties(objectHandle, fromCount, totalCount, propertiesObject)); }
    static JsErrorCode WINAPI JsDiagGetObjectFromHandle(unsigned int handle, JsValueRef * handleObject) { return HOOK_JS_API(DiagGetObjectFromHandle(handle, handleObject)); }
    static JsErrorCode WINAPI JsDiagEvaluateUtf8(const char * expression, unsigned int stackFrameIndex, JsValueRef * evalResult) { return HOOK_JS_API(DiagEvaluateUtf8(expression, stackFrameIndex, evalResult)); }

    static JsErrorCode WINAPI JsValueToCharCopy(JsValueRef value, char **stringValue, size_t *length)
    {
        JsValueRef strValue;
        IfJsrtErrorFailLogAndRetErrorCode(ChakraRTInterface::JsConvertValueToString(value, &strValue));
        IfJsrtErrorFailLogAndRetErrorCode(ChakraRTInterface::JsStringToPointerUtf8Copy(strValue, stringValue, length));
        return JsNoError;
    }

    static JsErrorCode WINAPI JsRunScriptUtf8(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef *result) { return HOOK_JS_API(RunScriptUtf8(script, sourceContext, sourceUrl, result)); }
    static JsErrorCode WINAPI JsSerializeScriptUtf8(const char *script, ChakraBytePtr buffer, unsigned int *bufferSize) { return HOOK_JS_API(SerializeScriptUtf8(script, buffer, bufferSize)); }
    static JsErrorCode WINAPI JsRunSerializedScriptUtf8(JsSerializedScriptLoadUtf8SourceCallback scriptLoadCallback, JsSerializedScriptUnloadCallback scriptUnloadCallback, ChakraBytePtr buffer, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef * result) { return HOOK_JS_API(RunSerializedScriptUtf8(scriptLoadCallback, scriptUnloadCallback, buffer, sourceContext, sourceUrl, result)); }
    static JsErrorCode WINAPI JsRunModuleUtf8(const char *script, JsSourceContext sourceContext, const char *sourceUrl, JsValueRef *result) { return HOOK_JS_API(ExperimentalApiRunModuleUtf8(script, sourceContext, sourceUrl, result)); }
    static JsErrorCode WINAPI JsPointerToStringUtf8(const char *stringValue, size_t length, JsValueRef *value) { return HOOK_JS_API(PointerToStringUtf8(stringValue, length, value)); }
    static JsErrorCode WINAPI JsStringFree(char *stringValue) { return HOOK_JS_API(StringFree(stringValue)); }
    static JsErrorCode WINAPI JsTTDCreateRecordRuntime(JsRuntimeAttributes attributes, char* infoUri, size_t infoUriCount, UINT32 snapInterval, UINT32 snapHistoryLength, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime) { return HOOK_JS_API(TTDCreateRecordRuntime(attributes, infoUri, infoUriCount, snapInterval, snapHistoryLength, threadService, runtime)); }
    static JsErrorCode WINAPI JsTTDCreateDebugRuntime(JsRuntimeAttributes attributes, char* infoUri, size_t infoUriCount, JsThreadServiceCallback threadService, JsRuntimeHandle *runtime) { return HOOK_JS_API(TTDCreateDebugRuntime(attributes, infoUri, infoUriCount, threadService, runtime)); }
    static JsErrorCode WINAPI JsTTDCreateContext(JsRuntimeHandle runtime, JsContextRef *newContext) { return HOOK_JS_API(TTDCreateContext(runtime, newContext)); }
    static JsErrorCode WINAPI JsTTDRunScript(INT64 hostCallbackId, const char* script, DWORD_PTR sourceContext, const char* sourceUrl, JsValueRef* result) { return HOOK_JS_API(TTDRunScript(hostCallbackId, script, sourceContext, sourceUrl, result)); }
    static JsErrorCode WINAPI JsTTDCallFunction(INT64 hostCallbackId, JsValueRef function, JsValueRef* arguments, unsigned short argumentCount, JsValueRef *result) { return HOOK_JS_API(TTDCallFunction(hostCallbackId, function, arguments, argumentCount, result)); }

    static JsErrorCode WINAPI JsTTDSetIOCallbacks(JsRuntimeHandle runtime, JsTTDInitializeUriCallback ttdInitializeTTDUriFunction, JsTTDInitializeForWriteLogStreamCallback writeInitializeFunction, JsTTDGetLogStreamCallback getLogStreamInfo, JsTTDGetSnapshotStreamCallback getSnapshotStreamInfo, JsTTDGetSrcCodeStreamCallback getSrcCodeStreamInfo, JsTTDReadBytesFromStreamCallback readBytesFromStream, JsTTDWriteBytesToStreamCallback writeBytesToStream, JsTTDFlushAndCloseStreamCallback flushAndCloseStream) { return HOOK_JS_API(TTDSetIOCallbacks(runtime, ttdInitializeTTDUriFunction, writeInitializeFunction, getLogStreamInfo, getSnapshotStreamInfo, getSrcCodeStreamInfo, readBytesFromStream, writeBytesToStream, flushAndCloseStream)); }

    static JsErrorCode WINAPI JsTTDStartTimeTravelRecording() { return HOOK_JS_API(TTDStartTimeTravelRecording()); }
    static JsErrorCode WINAPI JsTTDStopTimeTravelRecording() { return HOOK_JS_API(TTDStopTimeTravelRecording()); }
    static JsErrorCode WINAPI JsTTDEmitTimeTravelRecording() { return HOOK_JS_API(TTDEmitTimeTravelRecording()); }
    static JsErrorCode WINAPI JsTTDStartTimeTravelDebugging() { return HOOK_JS_API(TTDStartTimeTravelDebugging()); }

    static JsErrorCode WINAPI JsTTDPauseTimeTravelBeforeRuntimeOperation() { return HOOK_JS_API(TTDPauseTimeTravelBeforeRuntimeOperation()); }
    static JsErrorCode WINAPI JsTTDReStartTimeTravelAfterRuntimeOperation() { return HOOK_JS_API(TTDReStartTimeTravelAfterRuntimeOperation()); }

    static JsErrorCode WINAPI JsTTDNotifyHostCallbackCreatedOrCanceled(bool isCreate, bool isCancel, bool isRepeating, JsValueRef function, INT64 callbackId) { return HOOK_JS_API(TTDNotifyHostCallbackCreatedOrCanceled(isCreate, isCancel, isRepeating, function, callbackId)); }
    static JsErrorCode WINAPI JsTTDNotifyYield() { return HOOK_JS_API(TTDNotifyYield()); }

    static JsErrorCode WINAPI JsTTDPrepContextsForTopLevelEventMove(JsRuntimeHandle runtimeHandle, INT64 targetEventTime, INT64* targetStartSnapTime) { return HOOK_JS_API(TTDPrepContextsForTopLevelEventMove(runtimeHandle, targetEventTime, targetStartSnapTime)); }
    static JsErrorCode WINAPI JsTTDMoveToTopLevelEvent(INT64 snapshotStartTime, INT64 eventTime) { return HOOK_JS_API(TTDMoveToTopLevelEvent(snapshotStartTime, eventTime)); }
    static JsErrorCode WINAPI JsTTDReplayExecution(INT64* rootEventTime) { return HOOK_JS_API(TTDReplayExecution(rootEventTime)); }
};

class AutoRestoreContext
{
public:
    AutoRestoreContext(JsContextRef newContext)
    {
        JsErrorCode errorCode = ChakraRTInterface::JsGetCurrentContext(&oldContext);
        Assert(errorCode == JsNoError);

        if (oldContext != newContext)
        {
            errorCode = ChakraRTInterface::JsSetCurrentContext(newContext);
            Assert(errorCode == JsNoError);
            contextChanged = true;
        }
        else
        {
            contextChanged = false;
        }
    }

    ~AutoRestoreContext()
    {
        if (contextChanged && oldContext != JS_INVALID_REFERENCE)
        {
            ChakraRTInterface::JsSetCurrentContext(oldContext);
        }
    }
private:
    JsContextRef oldContext;
    bool contextChanged;
};