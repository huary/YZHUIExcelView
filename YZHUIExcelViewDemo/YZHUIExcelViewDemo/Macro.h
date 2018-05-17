//
//  Macro.h
//  yxx_ios
//
//  Created by victor siu on 17/3/20.
//  Copyright © 2017年 GDtech. All rights reserved.
//

#ifndef Macro_h
#define Macro_h

#define __DEBUG__                           DEBUG

//日志打印
#ifdef DEBUG
//#   define NSLog(fmt, ...)                       NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#   define NSLog(fmt, ...)                       NSLog(fmt, ##__VA_ARGS__);
#else
#   define NSLog(...)
#endif

//导航栏的常量宏定义
#define NAVIGATION_ITEM_VIEW_SUBVIEWS_LEFT_SPACE                                (12)
#define NAVIGATION_ITEM_VIEW_SUBVIEWS_RIGHT_SPACE                               (20)
#define CUSTOM_NAVIGATION_ITEM_VIEW_SUBVIEWS_ITEM_SPACE                         (15)
#define SYSTEM_NAVIGATION_ITEM_VIEW_SUBVIEWS_ITEM_SPACE                         (15)
#define NAVIGATION_ITEM_VIEW_LEFT_BACK_ITEM_IMAGE_WITH_TITLE_SPACE              (5)

#define NAVIGATION_ITEM_MIN_WIDTH                                               (40)
//这个最好别修改，NAVIGATION_ITEM_HEIGHT_WITH_NAVIGATION_BAR_HEIGHT_RATIO这个和系统中的导航栏中返回按钮一样大小
#define NAVIGATION_ITEM_HEIGHT_WITH_NAVIGATION_BAR_HEIGHT_RATIO                 (0.5)
//这个是长方形图片导航栏按钮高度与导航栏高度的比例
#define IMAGE_NAVIGATION_ITEM_HEIGHT_WITH_NAVIGATION_BAR_HEIGHT_RATIO           (0.8)//   (0.4)
//这个是正方形图片导航栏按钮高度与导航栏高度的比例
#define SQUARE_IMAGE_NAVIGATION_ITEM_HEIGHT_WITH_NAVIGATION_BAR_HEIGHT_RATIO    (0.62)
#define SQUARE_IMAGE_WIDTH_WITH_HEIGHT_MIN_RATIO                                (0.95)
#define SQUARE_IMAGE_WIDTH_WITH_HEIGHT_MAX_RATIO                                (1.05)
#define IS_SQUARE_SIZE(SIZE)                                                    (SIZE.width/SIZE.height >= SQUARE_IMAGE_WIDTH_WITH_HEIGHT_MIN_RATIO && SIZE.width/SIZE.height <= SQUARE_IMAGE_WIDTH_WITH_HEIGHT_MAX_RATIO)

#define NAVIGATION_ITEM_TITLE_FONT             [UIFont fontWithName:@"Helvetica-Bold" size:17.0]

//常用的基础宏定义
#define TYPE_AND(VA,VB)                        ((VA)&(VB))
#define TYPE_OR(VA,VB)                         ((VA)|(VB))
#define TYPE_LS(VA,LN)                         ((VA) << (LN))
#define TYPE_RS(VA,RN)                         ((VA) >> (RN))
#define TYPE_NOT(VAL)                          (!(VAL))
#define TYPE_INT_MASK                          (-1)

#define TYPE_STR(NAME)                          @#NAME

//屏幕尺寸大小和导航栏的一些宏定义
#define SCREEN_BOUNDS                          [UIScreen mainScreen].bounds
#define SCREEN_SCALE                           [UIScreen mainScreen].scale

#define SCREEN_WIDTH                           [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT                          [UIScreen mainScreen].bounds.size.height


#define STATUS_BAR_ORIENTATION                 [UIApplication sharedApplication].statusBarOrientation
#define STATUS_BAR_FRAME                       [[UIApplication sharedApplication] statusBarFrame]
#define NAV_BAR_FRAME                          self.navigationController.navigationBar.frame
#define TAB_BAR_FRAME                          [BaseTabBarController shareBaseTabBarController].tabBar.frame

#define STATUS_BAR_HEIGHT                      [[UIApplication sharedApplication] statusBarFrame].size.height
#define CONST_STATUS_BAR_HEIGHT                 (20)
#define NAV_BAR_HEIGHT                         self.navigationController.navigationBar.frame.size.height
#define VIEW_NAV_BAR_HEIGHT                    self.viewController.navigationController.navigationBar.bounds.size.height
//#define TAB_BAR_HEIGHT                         [BaseTabBarController shareBaseTabBarController].tabBar.frame.size.height
#define CONST_NAV_BAR_HEIGHT                   (44)
#define TAB_BAR_HEIGHT                         [YZHTabBarController shareTabBarController].tabBar.frame.size.height

#define STATUS_NAV_BAR_HEIGHT                  (STATUS_BAR_HEIGHT + NAV_BAR_HEIGHT)
#define CONST_STATUS_NAV_BAR_HEIGHT            (64)
#define STATUS_NAV_TAB_BAR_HEIGHT              (STATUS_NAV_BAR_HEIGHT + TAB_BAR_HEIGHT)
#define VIEW_VISIBLE_HEIGHT                    (SCREEN_HEIGHT - STATUS_NAV_TAB_BAR_HEIGHT)

//颜色
#undef RGB
#define RGB(R,G,B)                              [UIColor colorWithRed:(R)/255.f green:(G)/255.f blue:(B)/255.f alpha:1.f]
#define RGBA(R,G,B,A)                           [UIColor colorWithRed:(R)/255.f green:(G)/255.f blue:(B)/255.f alpha:(A)/255.f];


#define RGB_WITH_INT_WITH_NO_ALPHA(C_INT)       RGB(TYPE_AND(TYPE_RS(C_INT,16),255),TYPE_AND(TYPE_RS(C_INT,8),255),TYPE_AND(C_INT,255))
#define RGB_WITH_STR_WITH_NO_ALPHA(C_STR)       RGB_WITH_INT_WITH_NO_ALPHA([(C_STR) integerValue])

#define RGB_WITH_INT_WITH_ALPHA(C_INT)          RGBA(TYPE_AND(TYPE_RS(C_INT,24),255),TYPE_AND(TYPE_RS(C_INT,16),255),TYPE_AND(TYPE_RS(C_INT,8),255),TYPE_AND(C_INT,255))
#define RGB_WITH_STR_WITH_ALPHA(C_STR)          RGB_WITH_INT_WITH_ALPHA([(C_STR) integerValue])

#define RAND_COLOR                              RGB(TYPE_AND(arc4random(),255),TYPE_AND(arc4random(),255),TYPE_AND(arc4random(),255))

#define CLEAR_COLOR                             [UIColor clearColor]
#define WHITE_COLOR                             [UIColor whiteColor]
#define BLACK_COLOR                             [UIColor blackColor]
#define BLUE_COLOR                              [UIColor blueColor]
#define RED_COLOR                               [UIColor redColor]
#define GRAY_COLOR                              [UIColor grayColor]
#define LIGHT_GRAY_COLOR                        [UIColor lightGrayColor]
#define PURPLE_COLOR                            [UIColor purpleColor]
#define YELLOW_COLOR                            [UIColor yellowColor]
#define GREEN_COLOR                             [UIColor greenColor]
#define ORANGE_COLOR                            [UIColor orangeColor]
#define BROWN_COLOR                             [UIColor brownColor]
#define GROUP_TABLEVIEW_BG_COLOR                [UIColor groupTableViewBackgroundColor]

#define RED_FROM_RGB_COLOR(COLOR)               ({ \
                                                    CGFloat _R_COLOR_ = 0; \
                                                    CGFloat _G_COLOR_ = 0; \
                                                    CGFloat _B_COLOR_ = 0; \
                                                    CGFloat _ALPHA_ = 0; \
                                                    [COLOR getRed:&_R_COLOR_ green:&_G_COLOR_ blue:&_B_COLOR_ alpha:&_ALPHA_]; \
                                                    _R_COLOR_; \
                                                })

#define GREEN_FROM_RGB_COLOR(COLOR)             ({ \
                                                    CGFloat _R_COLOR_ = 0; \
                                                    CGFloat _G_COLOR_ = 0; \
                                                    CGFloat _B_COLOR_ = 0; \
                                                    CGFloat _ALPHA_ = 0; \
                                                    [COLOR getRed:&_R_COLOR_ green:&_G_COLOR_ blue:&_B_COLOR_ alpha:&_ALPHA_]; \
                                                    _G_COLOR_; \
                                                })

#define BLUE_FROM_RGB_COLOR(COLOR)              ({ \
                                                    CGFloat _R_COLOR_ = 0; \
                                                    CGFloat _G_COLOR_ = 0; \
                                                    CGFloat _B_COLOR_ = 0; \
                                                    CGFloat _ALPHA_ = 0; \
                                                    [COLOR getRed:&_R_COLOR_ green:&_G_COLOR_ blue:&_B_COLOR_ alpha:&_ALPHA_]; \
                                                    _B_COLOR_; \
                                                })

#define ALPHA_FROM_RGB_COLOR(COLOR)             ({ \
                                                    CGFloat _R_COLOR_ = 0; \
                                                    CGFloat _G_COLOR_ = 0; \
                                                    CGFloat _B_COLOR_ = 0; \
                                                    CGFloat _ALPHA_ = 0; \
                                                    [COLOR getRed:&_R_COLOR_ green:&_G_COLOR_ blue:&_B_COLOR_ alpha:&_ALPHA_]; \
                                                    _ALPHA_; \
                                                })

#define NSOBJECT_FORMAT                         @"%@"
#define INTEGER_FORMAT                          @"%ld"
#define LLONG_INTEGER_FORMAT                    @"%lld"
#define INTEGER_WITH_SPACE_FORMAT               @"%ld "
#define INTEGER_WITH_SPACE_ANOTHER_FORMAT       @"%ld %@"
#define FLOAT_2D_NSOBJECT_FORMAT                @"%.2f %@"
//NSString的一些常用用定义
#define NEW_STRING(STRING)                      ((STRING != nil) ? [[NSString alloc] initWithString:STRING] : (nil))
#define NEW_NORMAL_FORMAT_STRING(OBJ)           ((OBJ) ? [[NSString alloc] initWithFormat:NSOBJECT_FORMAT,OBJ] : (nil))
#define NEW_DATA(DATA)                          ((DATA) ? [[NSData alloc] initWithData:DATA] : (nil))
#define STRING_FORMAT(FORMAT,...)               [NSString stringWithFormat:FORMAT,##__VA_ARGS__]
#define NEW_STRING_WITH_FORMAT(FORMAT,...)      [[NSString alloc] initWithFormat:FORMAT,##__VA_ARGS__]

//判断可用的NSOBject对象
#define IS_AVAILABLE_NSSTRNG(STRING)            (STRING != nil && STRING.length > 0)
#define IS_AVAILABLE_NSSET_OBJ(NSSET_OBJ)       (NSSET_OBJ != nil && NSSET_OBJ.count > 0)
#define IS_AVAILABLE_NSOBJECT_NOT_NULL(OBJ)     ((OBJ) != nil &&  (OBJ) != [NSNull null])
#define IS_AVAILABLE_CGSIZE(SIZE)               ((SIZE.width >0) && (SIZE.height > 0))


//返回的一些安全操作
#define NSOBJECT_SAFE_GET_NONULL_VAL(VAL)       (VAL) ? (VAL) : @""
#define NSOBJECT_SAFE_RET_NONULL_VAL(VAL)       return ((VAL) ? (VAL) : @"")

#define NSSTRING_SAFE_GET_NONULL_VAL(VAL)       (VAL) ? (VAL) : @""
#define NSSTRING_SAFE_RET_NONULL_VAL(VAL)       return ((VAL) ? (VAL) : @"")

#define NSARRAY_SAFE_GET_NONULL_VAL(VAL)        (VAL) ? (VAL) : (@[])
#define NSARRAY_SAFE_RET_NONULL_VAL(VAL)        return ((VAL) ? (VAL) : (@[]))

#define NSDICTIONARY_SAFE_GET_NONULL_VAL(VAL)   (VAL) ? (VAL) : (@{})
#define NSDICTIONARY_SAFE_RET_NONULL_VAL(VAL)   return ((VAL) ? (VAL) : (@{}))

//获取class的string的互转
#define NSSTRING_FROM_CLASS(CLASS_NAME)         NSStringFromClass([CLASS_NAME class])
#define NSCLASS_FROM_STRING(CLASS_STRING)       NSClassFromString(CLASS_STRING)
#define CLASS_NAME_STRING_FOR_NSOBJ(NSOBJ)      NSStringFromClass([NSOBJ class])
#define NSOBJ_TYPE_IS_CLASS(NSOBJ,CLASS_NAME)   [CLASS_NAME_STRING_FOR_NSOBJ(NSOBJ) isEqualToString:NSSTRING_FROM_CLASS(CLASS_NAME)]

#define CLASS_FROM_CLASSNAME(CLASS_NAME)        [CLASS_NAME class]

#define IS_SYSTEM_CLASS(CLASS)                  ([NSBundle bundleForClass:CLASS] != [NSBundle mainBundle])
#define IS_SYSTEM_CLASS_FROM_STRING(CLASS_NAME) IS_SYSTEM_CLASS(NSClassFromString(CLASS_NAME))

//selector和string的互转
#define NSSELECTOR_FROM_STRING(STRING)          NSSelectorFromString(STRING)
#define NSSTRING_FROM_SELECTOR(SELECTOR)        NSStringFromSelector(SELECTOR)

//NSURL
#define NSURL_FROM_STRING(STRING_URL)           [NSURL URLWithString:STRING_URL]
#define NSURL_FROM_FILE_PATH(FILE_PATH)         [NSURL fileURLWithPath:FILE_PATH]

//字体
#define FONT(F_S)                               [UIFont systemFontOfSize:(F_S)]
#define BOLD_FONT(F_S)                          [UIFont boldSystemFontOfSize:(F_S)]

//弱引用
#define WEAK_NSOBJ(NSOBJ,WEAK_NAME)             __weak __typeof(&*NSOBJ) WEAK_NAME = NSOBJ
#define WEAK_SELF(WEAK_NAME)                    __weak __typeof(&*self) WEAK_NAME = self

//本地化的操作
#define NSLOCAL_STRING(TEXT)                    NSLocalizedString(TEXT, nil)

//获取系统的版本号
#define SYSTEMVERSION_NUMBER                    [[UIDevice currentDevice].systemVersion floatValue]

//在主线程工作
#define DISPATCH_MAIN_THREAD_SYNC(BLOCK)        do{ \
                                                    if ([NSThread isMainThread]) \
                                                    { \
                                                        BLOCK(); \
                                                    } \
                                                    else \
                                                    { \
                                                        dispatch_sync(dispatch_get_main_queue(), BLOCK);\
                                                    } \
                                                }while(0);
//在主线程异步工作
#define DISPATCH_MAIN_THREAD_ASYNC(BLOCK)       do{ \
                                                    if ([NSThread isMainThread]) \
                                                    { \
                                                        BLOCK(); \
                                                    } \
                                                    else \
                                                    { \
                                                        dispatch_async(dispatch_get_main_queue(), BLOCK);\
                                                    } \
                                                }while(0);

#define TYPE_INT_ZERO_SELECT_ONE(V)             (((V) == 0) ? (1) : (V))
#define IS_RANGE_LENGTH_ZERO(RANGE)             ((RANGE.length == 0) ? (1) : (0))
#define NSRANGE_ZERO                            ({const NSRange NSRangeZero={.location=0,.length=0}; NSRangeZero;})

//从nsdictionary取值
#define ASSIGN_VAR_FROM_DICTIONARY(VAR,DICT,KEY,TYPE)    ((DICT[KEY]) ? (VAR = [DICT[KEY] TYPE]) : (VAR))
#define GET_NSOBJ_FROM_DICTIONARY(NSOBJ,DICT,KEY)        ((DICT[KEY]) ? (NSOBJ = DICT[KEY]) : (NSOBJ))

//以下宏定义可能会与业务需求相关
//字节单位
#define KB_VALUE                                (1024)
#define MB_VALUE                                (1048576)
#define GB_VALUE                                (1073741824)
#define KB_NAME_STR                             @"KB"
#define MB_NAME_STR                             @"MB"
#define GB_NAME_STR                             @"GB"

//时间单位
#define TIME_MIN_SEC                            (60)
#define TIME_HOUR_SEC                           (3600)
#define TIME_SEC_MSEC                           (1000)
#define TIME_ONE_HUNDRED_MIN                    (6000)

#define TIME_SEC_TEXT                           NSLOCAL_STRING(@"秒")
#define TIME_MIN_TEXT                           NSLOCAL_STRING(@"分")
#define TIME_HOUR_TEXT                          NSLOCAL_STRING(@"小时")

//计数单位
#define TEN_THOUSAND                            (10000)
#define TEN_THOUSAN_NAME                        NSLOCAL_STRING(@"万") //(@"万")

#define THOUSAND                                (1000)
#define THOUSAN_NAME                            NSLOCAL_STRING(@"千") //(@"万")

#define MILLION                                 (1000000)
#define MILLION_NAME                            NSLOCAL_STRING(@"百万")

#define FILE_SIZE_TEXT                          NSLOCAL_STRING(@"")//NSLOCAL_STRING(@"大小：")
//#define DOWNLOAD_TIMES_TEXT                     NSLOCAL_STRING(@"次下载")
//#define PEOPLE_LIKE_TEXT                        NSLOCAL_STRING(@"人喜欢")
//#define PEOPLE_PRAISE_TEXT                      NSLOCAL_STRING(@"人点赞")
//#define APP_VERSION_TEXT                        NSLOCAL_STRING(@"版本：")
//#define APP_UPDATE_TIME_TEXT                    NSLOCAL_STRING(@"更新时间：")
//#define TIME_INTERVAL_TEXT                      NSLOCAL_STRING(@"时长：")
//#define SPEED_UINT_FROM_STR                     @"/S"

//已GB,MB为单位,如50GB20MB
#define GB_MB_UNIT_STR(SIZE)                    (((SIZE) > (GB_VALUE)) ? STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT,(SIZE) * 1.0/(GB_VALUE),GB_NAME_STR) : STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT,(SIZE) * 1.0/(MB_VALUE),MB_NAME_STR))

//已MB，KB为单位，如2000MB500KB
#define MB_KB_UNIT_STR(SIZE)                    (((SIZE) > (MB_VALUE)) ? STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT,(SIZE) * 1.0/(MB_VALUE),MB_NAME_STR) : STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT,(SIZE)*1.0/(KB_VALUE),KB_NAME_STR))

//以GB，MB或者KB为单位，
//1、如20GB200MB，
//2、如500MB
//3、如20KB
#define MB_UNIT_STR(SIZE)                       (((SIZE) > (MB_VALUE)) ? GB_MB_UNIT_STR(SIZE) : STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT,(SIZE)*1.0/(KB_VALUE),KB_NAME_STR))


#define FILE_SIZE_DESCRIPTION(FILE_SIZE)        [NSString stringWithFormat:@"%@%@",FILE_SIZE_TEXT,MB_UNIT_STR(FILE_SIZE)]

//计数
//以万为单位
#define TEN_THOUSAND_UNIT_STR(CNT)              (((CNT) > (TEN_THOUSAND)) ? STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT, (CNT)*1.0/TEN_THOUSAND,TEN_THOUSAN_NAME) : STRING_FORMAT(INTEGER_WITH_SPACE_FORMAT,CNT))


//以千为单位
#define THOUSAND_UNIT_STR(CNT)                  (((CNT) > THOUSAND) ? ( ((CNT) > MILLION) ? STRING_FORMAT(FLOAT_2D_NSOBJECT_FORMAT, (CGFloat)(CNT)*1.0/MILLION,MILLION_NAME) : STRING_FORMAT(INTEGER_WITH_SPACE_ANOTHER_FORMAT, (CNT)/THOUSAND, THOUSAN_NAME)) : (STRING_FORMAT(INTEGER_WITH_SPACE_FORMAT,CNT)))


//#define NUMBER_UNIT_STR(CNT)                   ({ \
//                                                    LanguageType languageType = [LanguageUtils currentLanguage]; \
//                                                    NSString *DEFAULT_UNIT_STR = TEN_THOUSAND_UNIT_STR(CNT); \
//                                                    if (languageType == LanguageType_en) \
//                                                        DEFAULT_UNIT_STR = THOUSAND_UNIT_STR(CNT); \
//                                                    else if (languageType == LanguageType_es) \
//                                                        DEFAULT_UNIT_STR = THOUSAND_UNIT_STR(CNT); \
//                                                    else if (languageType == LanguageType_fr) \
//                                                        DEFAULT_UNIT_STR = THOUSAND_UNIT_STR(CNT); \
//                                                    else if (languageType == LanguageType_JP) \
//                                                        DEFAULT_UNIT_STR = THOUSAND_UNIT_STR(CNT); \
//                                                    DEFAULT_UNIT_STR; \
//                                                })


//00(分钟):00(秒)
#define TIME_SECOND_UNIT_STR(SEC)                   (((SEC) >= TIME_ONE_HUNDRED_MIN) ? STRING_FORMAT(@"%03d:%02d",(int)(SEC)/60,(int)(SEC)%60) : STRING_FORMAT(@"%02d:%02d",(int)(SEC)/60,(int)(SEC)%60))

//xx小时xx分xx秒 格式
#define TIME_TEXT_FORMAT_HMS(SEC)                   (((SEC) >= TIME_MIN_SEC) ? (((SEC) >= TIME_HOUR_SEC) ? STRING_FORMAT(@"%d%@%d%@%d%@",(SEC)/TIME_HOUR_SEC,TIME_HOUR_TEXT, ((SEC)%TIME_HOUR_SEC)/TIME_MIN_SEC,TIME_MIN_TEXT, (SEC)%TIME_MIN_SEC,TIME_SEC_TEXT) : STRING_FORMAT(@"%d%@%d%@",(SEC)/TIME_MIN_SEC,TIME_MIN_TEXT, ((SEC)%TIME_MIN_SEC),TIME_SEC_TEXT)) : STRING_FORMAT(@"%d%@",SEC,TIME_SEC_TEXT))

//00:00:00格式
#define TIME_TEXT_FORMAT_COLON(SEC)                 (((SEC) >= TIME_MIN_SEC) ? (((SEC) >= TIME_HOUR_SEC) ? STRING_FORMAT(@"%02d:%02d:%02d",(SEC)/TIME_HOUR_SEC, ((SEC)%TIME_HOUR_SEC)/TIME_MIN_SEC, (SEC)%TIME_MIN_SEC) : STRING_FORMAT(@"00:%02d:%02d",(SEC)/TIME_MIN_SEC, ((SEC)%TIME_MIN_SEC),TIME_SEC_TEXT)) : STRING_FORMAT(@"00:00:%02d",SEC))

#define TIME_TEXT_FORMAT_COLON_WITH_MSEC(MSEC)      TIME_TEXT((unsigned int)(MSEC)/TIME_SEC_MSEC)

#define TIME_MSECOND_UNIT_STR(MSEC)                 TIME_SECOND_UNIT_STR((NSInteger)(MSEC)/TIME_SEC_MSEC)


//-------数据模型请求下来的，比较特殊的宏定义
//#define DATA_KEY                                TYPE_STR(data)

//#define NSOBJECT_VALUE(DATA,NAME)               DATA[DATA_KEY][TYPE_STR(NAME)]
//#define STRING_VALUE(DATA,NAME)                 NSOBJECT_VALUE(DATA,NAME)
//#define BOOL_VALUE(DATA,NAME)                   [NSOBJECT_VALUE(DATA, NAME) boolValue]
//#define FLOAT_VALUE(DATA,NAME)                  [NSOBJECT_VALUE(DATA, NAME) floatValue]
//#define INTEGER_VALUE(DATA,NAME)                [NSOBJECT_VALUE(DATA, NAME) integerValue]
//#define INT_VALUE(DATA,NAME)                    [NSOBJECT_VALUE(DATA, NAME) intValue]
//#define NEW_STRING_FORMAT(DATA,NAME)            [[NSString alloc] initWithFormat:NSOBJECT_FORMAT,DATA[DATA_KEY][TYPE_STR(NAME)]]

#define NSOBJECT_VALUE(DATA,NAME)               DATA[TYPE_STR(NAME)]
#define STRING_VALUE(DATA,NAME)                 NSOBJECT_VALUE(DATA,NAME)
#define BOOL_VALUE(DATA,NAME)                   [NSOBJECT_VALUE(DATA, NAME) boolValue]
#define FLOAT_VALUE(DATA,NAME)                  [NSOBJECT_VALUE(DATA, NAME) floatValue]
#define INTEGER_VALUE(DATA,NAME)                [NSOBJECT_VALUE(DATA, NAME) integerValue]
#define INT_VALUE(DATA,NAME)                    [NSOBJECT_VALUE(DATA, NAME) intValue]
#define NEW_STRING_FORMAT(DATA,NAME)            [[NSString alloc] initWithFormat:NSOBJECT_FORMAT,DATA[TYPE_STR(NAME)]]

//-------数据模型请求下来的，比较特殊的宏定义，end

//n倍向上取整
#define CEIL_TIMES(VAL,D)               ((VAL) == 0 ? (VAL) : ( (VAL) > 0 ? ((((VAL)-1)/D + 1) * D) : ((((VAL)+1)/D+1)*D)))

#define RADIANS_TO_DEGREES(radians)             ((radians) * (180.0 / M_PI))
#define DEGREES_TO_RADIANS(angle)               ((angle) / 180.0 * M_PI)

//cgsize
#define CGSizeLessThanToSize(SIZE1,SIZE2)           ((SIZE1.width < SIZE2.width) && (SIZE1.height < SIZE2.height))
#define CGSizeLessEqualToSize(SIZE1,SIZE2)          ((SIZE1.width <= SIZE2.width) && (SIZE1.height <= SIZE2.height))
#define CGSizeGreaterThanToSize(SIZE1,SIZE2)        ((SIZE1.width > SIZE2.width) && (SIZE1.height > SIZE2.height))
#define CGSizeGreaterEqualToSize(SIZE1,SIZE2)       ((SIZE1.width >= SIZE2.width) && (SIZE1.height >= SIZE2.height))

#define CGPointGeneralEqualToPoint(PT1,PT2)         ((((NSInteger)PT1.x) == ((NSInteger)PT2.x)) && (((NSInteger)PT1.y) == ((NSInteger)PT2.y)))

//cgrect
#define CGRECT_CENTER_POINT(RECT)                    CGPointMake(CGRectGetMidX(RECT), CGRectGetMidY(RECT))
#define CGRECT_ACREAGE(RECT)                         (RECT.size.width * RECT.size.height)

//易学习需要的宏定义
#define AT_ALL_FRIEND_STR                               @"All"
#define REVERSE_INDEX_FOR_CNT(INDEX,CNT)                MAX(((CNT)-1-INDEX),0)
#define REVERSE_INDEX_PATH_FOR_TABLE(INDEX_PATH,CNT)    [NSIndexPath indexPathForRow:REVERSE_INDEX_FOR_CNT(INDEX_PATH.row,CNT) inSection:INDEX_PATH.section];


#define IMPLEMENTATION_FOR_CLASS(CLASS)                 @implementation CLASS @end

#define UIIMAGE_NAME_IN_BUNDLE(IMAGE_NAME)              TYPE_STR(IMAGE_NAME)

// 易学习中统一的颜色
// 工程统一标准
// Color
//主色蓝
#define MainColor [UIColor colorWithHexString:@"#35a3dd"]
//主色红
#define MainRedColor [UIColor colorWithHexString:@"#dd3f35"]
#define WhiteColorOne [UIColor colorWithHexString:@"#ffffff"]
#define WhiteColorTwo [UIColor colorWithHexString:@"#efefef"]
#define WhiteColorThree [UIColor colorWithHexString:@"#dddddd"]
#define WhiteColorFour [UIColor colorWithHexString:@"#999999"]
#define WhiteColorFive [UIColor colorWithHexString:@"#666666"]
#define WhiteColorSix [UIColor colorWithHexString:@"#333333"]
//辅色红
#define RedSpecialColor [UIColor colorWithHexString:@"#eb7778"]
//辅色橙
#define OrangeSpecialColor [UIColor colorWithHexString:@"#f2b266"]
//辅色绿
#define GreenSpecialColor [UIColor colorWithHexString:@"#7acda1"]
#define CyanSpecialColor [UIColor colorWithHexString:@"#d7edf8"]
#define BlueSpecialColor [UIColor colorWithHexString:@"#008dd8"]

#define LightBlueSpecialColor   RGB_WITH_INT_WITH_NO_ALPHA(0xedf9ff)


//易打分
#define NET_REQUEST_TIME_OUT_INTERVAL           (30)
#define PEN_DEVICE_REQUEST_TIME_OUT_INTERVAL    (20)
#define DATE_STRING_FORMAT                      @"yyyy-MM-dd HH:mm:ss"
#define USEC_FROM_DATE_SINCE1970(DATE)           ((uint64_t)([DATE timeIntervalSince1970] * USEC_PER_SEC))
#define DATE_FROM_USEC_SINCE1970(TIME)           ([NSDate dateWithTimeIntervalSince1970:TIME * 1.0/USEC_PER_SEC])

#define MSEC_PER_SEC                             (1000)
#define MSEC_FROM_DATE_SINCE1970(DATE)           ((uint64_t)([DATE timeIntervalSince1970] * MSEC_PER_SEC))
#define DATE_FROM_MSEC_SINCE1970(TIME)           ([NSDate dateWithTimeIntervalSince1970:TIME * 1.0/MSEC_PER_SEC])


//DBTable

#define DB_PROPERTY_UPDATE(typeName ,propertyName)       -(void)update:(BOOL)update propertyName:(typeName)propertyName;
#define __DB_OC_PROPERTY_UPDATE_SYNTHESIZE(typeName, propertyName, tableName, condition)      \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName                          \
    {                                                                                       \
        self.propertyName = propertyName;                                                   \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:propertyName where:condition];                       \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
    }

#define __DB_C_PROPERTY_UPDATE_SYNTHESIZE(typeName, propertyName, tableName, condition)       \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName                          \
    {                                                                                       \
        self.propertyName = propertyName;                                                   \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:@(propertyName) where:condition];                    \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
    }


#define __DB_OC_KEY_PROPERTY_UPDATE_SYNTHESIZE(typeName ,propertyName, tableName, condition)      \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName                          \
    {                                                                                       \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:propertyName where:condition];                       \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
        self.propertyName = propertyName;                                                   \
    }

#define __DB_C_KEY_PROPERTY_UPDATE_SYNTHESIZE(typeName, propertyName, tableName, condition)       \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName                          \
    {                                                                                       \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:@(propertyName) where:condition];                    \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
        self.propertyName = propertyName;                                                   \
    }




#define DB_PROPERTY_UPDATE_ON_TB(typeName ,propertyName)       -(void)update:(BOOL)update propertyName:(typeName)propertyName onTable:(NSString *)tableName;
#define __DB_OC_PROPERTY_UPDATE_ON_TB_SYNTHESIZE(typeName, propertyName, condition)      \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName onTable:(NSString *)tableName    \
    {                                                                                       \
        self.propertyName = propertyName;                                                   \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:propertyName where:condition];                       \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
    }

#define __DB_C_PROPERTY_UPDATE_ON_TB_SYNTHESIZE(typeName, propertyName, condition)       \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName onTable:(NSString *)tableName    \
    {                                                                                       \
        self.propertyName = propertyName;                                                   \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:@(propertyName) where:condition];                    \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
    }


#define __DB_OC_KEY_PROPERTY_UPDATE_ON_TB_SYNTHESIZE(typeName ,propertyName, condition)      \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName onTable:(NSString *)tableName        \
    {                                                                                       \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:propertyName where:condition];                       \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
        self.propertyName = propertyName;                                                   \
    }

#define __DB_C_KEY_PROPERTY_UPDATE_ON_TB_SYNTHESIZE(typeName, propertyName, condition)       \
    -(void)update:(BOOL)update propertyName:(typeName)propertyName onTable:(NSString *)tableName        \
    {                                                                                       \
        if (update)                                                                         \
        {                                                                                   \
            [[DataManager shareDataManager] addDBExecute:^id{                               \
            [[DataManager shareDataManager].shareDatabase updateRowsInTable:tableName onProperty:[self class].propertyName withValue:@(propertyName) where:condition];                    \
            return nil;                                                                     \
            } completionBlock:nil];                                                         \
        }                                                                                   \
        self.propertyName = propertyName;                                                   \
    }


#endif /* Macro_h */


