//
//  DWTagList.h
//
//  Created by Dominic Wroblewski on 07/07/2012.
//  Copyright (c) 2012 Terracoding LTD. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DWTagListDelegate, DWTagViewDelegate;

@class DWTagView;

@interface DWTagList : UIScrollView
{
    UIView      *view;
    NSArray     *textArray;
    CGSize      sizeFit;
    UIColor     *lblBackgroundColor;
}

@property (nonatomic) BOOL viewOnly;
@property (nonatomic) BOOL showTagMenu;
@property (nonatomic, strong) UIView *view;
@property (nonatomic, strong) NSArray *textArray;
@property (nonatomic, weak) id<DWTagListDelegate> tagDelegate;
@property (nonatomic, strong) UIColor *highlightedBackgroundColor;
@property (nonatomic) BOOL automaticResize;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, assign) CGFloat labelMargin;
@property (nonatomic, assign) CGFloat bottomMargin;
@property (nonatomic, assign) CGFloat horizontalPadding;
@property (nonatomic, assign) CGFloat verticalPadding;
@property (nonatomic, assign) CGFloat minimumWidth;
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *textShadowColor;
@property (nonatomic, assign) CGSize textShadowOffset;
// added by adaiye
@property (nonatomic, strong) UIColor *highlightedBorderColor;
@property (nonatomic, strong) UIColor *highlightedTextColor;
@property (nonatomic, assign) BOOL selectedOnTapped;
@property (nonatomic, assign) BOOL showDottedAtLast;
@property (nonatomic, strong) NSString *lastDottedText;
@property (nonatomic, strong) DWTagView *lastDottedView;
@property (nonatomic, readonly) NSArray *selectedTags;

- (void)setTagBackgroundColor:(UIColor *)color;
- (void)setTagHighlightColor:(UIColor *)color;
- (void)setTags:(NSArray *)array;
- (void)addTag:(NSString *)tag;
- (void)display;
- (CGSize)fittedSize;
- (void)scrollToBottomAnimated:(BOOL)animated;

@end

@interface DWTagView : UIView

@property (nonatomic, strong) UIButton              *button;
@property (nonatomic, strong) UILabel               *label;
@property (nonatomic, weak)   id<DWTagViewDelegate> delegate;

- (void)updateWithString:(NSString*)text
                    font:(UIFont*)font
      constrainedToWidth:(CGFloat)maxWidth
                 padding:(CGSize)padding
            minimumWidth:(CGFloat)minimumWidth;
- (void)setLabelText:(NSString*)text;
- (void)setCornerRadius:(CGFloat)cornerRadius;
- (void)setBorderColor:(CGColorRef)borderColor;
- (void)setBorderWidth:(CGFloat)borderWidth;
- (void)setTextColor:(UIColor*)textColor;
- (void)setTextShadowColor:(UIColor*)textShadowColor;
- (void)setTextShadowOffset:(CGSize)textShadowOffset;

@end


@protocol DWTagListDelegate <NSObject>

@optional

- (void)selectedTag:(NSString *)tagName tagIndex:(NSInteger)tagIndex;
- (void)selectedTag:(NSString *)tagName;
- (void)tagListTagsChanged:(DWTagList *)tagList;

@end

@protocol DWTagViewDelegate <NSObject>

@required

- (void)tagViewWantsToBeDeleted:(DWTagView *)tagView;

@end
