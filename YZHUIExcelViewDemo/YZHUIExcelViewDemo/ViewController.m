//
//  ViewController.m
//  YZHUIExcelViewDemo
//
//  Created by yuan on 2017/9/20.
//  Copyright © 2017年 yuan. All rights reserved.
//

#import "ViewController.h"
#import "YZHUIExcelView.h"
#import "reuseCell.h"


@interface ViewController ()<YZHUIExcelViewDelegate>

@property (nonatomic, strong) YZHUIExcelView *excelView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self _setupChildView];
}

-(void)_setupChildView
{
    CGFloat width = SCREEN_WIDTH * 0.96;
    CGFloat height = SCREEN_HEIGHT - 40;
    CGFloat x = (SCREEN_WIDTH - width)/2;
    CGFloat y = (SCREEN_HEIGHT - height)/2;
    self.excelView = [[YZHUIExcelView alloc] init];
    self.excelView.frame = CGRectMake(x, y, width, height);
    self.excelView.verticalLineType = NSExcelSeparatorLineTypeSingleLine;
    self.excelView.verticalLineColor = LIGHT_GRAY_COLOR;
    self.excelView.horizontalLineType = NSExcelSeparatorLineTypeSingleLine;
    self.excelView.horizontalLineColor = LIGHT_GRAY_COLOR;
    self.excelView.lockIndexPath = [NSIndexPath indexPathForExcelRow:1 excelColumn:0];
    self.excelView.delegate = self;
    [self.view addSubview:self.excelView];
}


#pragma mark YZHUIExcelViewDelegate

-(NSInteger)numberOfRowsInExcelView:(YZHUIExcelView *)excelView
{
    return 100;
}

-(NSInteger)numberOfColumnsInExcelView:(YZHUIExcelView *)excelView
{
    return 100;
}

-(CGFloat)excelView:(YZHUIExcelView *)excelView heightForRowAtIndex:(NSInteger)rowIndex
{
    return 40;
}

-(CGFloat)excelView:(YZHUIExcelView *)excelView widthForColumnAtIndex:(NSInteger)columnIndex
{
    return 80;
}

-(UIView*)excelView:(YZHUIExcelView *)excelView excelCellForItemAtIndexPath:(NSIndexPath*)indexPath withReusableExcelCellView:(UIView *)reusableExcelCellView
{
    
    reuseCell *cell = (reuseCell*)reusableExcelCellView;
    if (cell == nil) {
        cell = [[reuseCell alloc] init];
    }
    cell.textLabel.text = NEW_STRING_WITH_FORMAT(@"(%ld,%ld)",indexPath.excelRow,indexPath.excelColumn);
    return cell;
    
//    NSScoreConfirmModel *model = self.confirmDatas[indexPath.excelRow];
//    UIScoreConfirmExcelCell *cell = (UIScoreConfirmExcelCell*)reusableExcelCellView;
//    if (cell == nil) {
//        cell = [[UIScoreConfirmExcelCell alloc] init];
//    }
//
//    //    if (indexPath.excelColumn == 0) {
//    //        cell.textLabel.text = model.studentId;
//    //    }
//    //    else
//    if (indexPath.excelColumn == 0)
//    {
//        cell.textLabel.text = model.studentName;
//    }
//    else if (indexPath.excelColumn == 1)
//    {
//        cell.textLabel.text = model.paperId;
//    }
//    else
//    {
//        cell.textLabel.text = model.questionScore;
//    }
//    cell.textLabel.textColor= model.textColor;
//
//    if (indexPath.excelRow == 0) {
//        cell.backgroundColor = CyanSpecialColor;
//    }
//    else
//    {
//        cell.backgroundColor = White_BD_Color;
//    }
//    return cell;
}

-(void)excelView:(YZHUIExcelView *)excelView didSelectExcelCellItemAtIndexPath:(NSIndexPath *)indexPath withReusableExcelCellView:(UIView *)reusableExcelCellView
{
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
