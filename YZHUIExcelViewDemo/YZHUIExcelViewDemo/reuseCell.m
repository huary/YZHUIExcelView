//
//  reuseCell.m
//  YZHUIExcelViewDemo
//
//  Created by yuan on 2018/5/12.
//  Copyright © 2018年 yuan. All rights reserved.
//

#import "reuseCell.h"

@implementation reuseCell

-(instancetype)init
{
    self = [super init];
    if (self) {
        [self _setupExcelCellSubView];
    }
    return self;
}

-(void)_setupExcelCellSubView
{
    UILabel *textLabel =[[UILabel alloc] init];
    textLabel.font = FONT(16);
    textLabel.textAlignment = NSTextAlignmentCenter;
    [self addSubview:textLabel];
    
    _textLabel = textLabel;
}

-(void)layoutSubviews
{
    [super layoutSubviews];
    self.textLabel.frame = self.bounds;
}


@end
