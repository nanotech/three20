#import "Three20/TTModelViewController.h"
#import "Three20/TTTableViewDataSource.h"
#import "Three20/TTActivityLabel.h"

@interface TTTableViewController : TTModelViewController {
  UITableView* _tableView;
  UIView* _tableBannerView;
  UIView* _tableOverlayView;
  UIView* _loadingView;
  UIView* _errorView;
  UIView* _emptyView;
  UIView* _menuView;
  UITableViewCell* _menuCell;
  id<TTTableViewDataSource> _dataSource;
  id<UITableViewDelegate> _tableDelegate;
  NSTimer* _bannerTimer;
  UITableViewStyle _tableViewStyle;
  UIInterfaceOrientation _lastInterfaceOrientation;
  BOOL _variableHeightRows;
  TTActivityLabelStyle _activityLabelStyle;
}

@property(nonatomic,retain) UITableView* tableView;

/**
 * A view that is displayed as a banner at the bottom of the table view.
 */
@property(nonatomic,retain) UIView* tableBannerView;

/**
 * A view that is displayed over the table view.
 */
@property(nonatomic,retain) UIView* tableOverlayView;

@property(nonatomic,retain) UIView* loadingView;
@property(nonatomic,retain) UIView* errorView;
@property(nonatomic,retain) UIView* emptyView;

@property(nonatomic,readonly) UIView* menuView;

@property(nonatomic,assign) TTActivityLabelStyle activityLabelStyle;

/** 
 * The data source used to populate the table view.
 *
 * Setting dataSource has the side effect of also setting model to the value of the
 * dataSource's model property.
 */
@property(nonatomic,retain) id<TTTableViewDataSource> dataSource;

/**
 * The style of the table view.
 */
@property(nonatomic) UITableViewStyle tableViewStyle;

/**
 * Override to use a custom UITableView subclass.
 */
- (UITableView*)createTableViewWithFrame:(CGRect)frame style:(UITableViewStyle)style;

/** 
 * Indicates if the table should support non-fixed row heights.
 */
@property(nonatomic) BOOL variableHeightRows;

/**
 * Initializes and returns a controller having the given style.
 */
- (id)initWithStyle:(UITableViewStyle)style;

/**
 * Creates an delegate for the table view.
 *
 * Subclasses can override this to provide their own table delegate implementation.
 */
- (id<UITableViewDelegate>)createDelegate;

/**
 * Sets the view that is displayed at the bottom of the table view with an optional animation.
 */
- (void)setTableBannerView:(UIView*)tableBannerView animated:(BOOL)animated;

/**
 * Shows a menu over a table cell.
 */
- (void)showMenu:(UIView*)view forCell:(UITableViewCell*)cell animated:(BOOL)animated;

/**
 * Hides the currently visible table cell menu.
 */
- (void)hideMenu:(BOOL)animated;

/**
 * Tells the controller that the user selected an object in the table.
 *
 * By default, the object's URLValue will be opened in TTNavigator, if it has one. If you don't
 * want this to be happen, be sure to override this method and be sure not to call super.
 */
- (void)didSelectObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 * Asks if a URL from that user touched in the table should be opened.
 */
- (BOOL)shouldOpenURL:(NSString*)URL;

/**
 * Tells the controller that the user began dragging the table view.
 */
- (void)didBeginDragging;

/**
 * Tells the controller that the user stopped dragging the table view.
 */
- (void)didEndDragging;

/**
 * The rectangle where the overlay view should appear.
 */
- (CGRect)rectForOverlayView;

/**
 * The rectangle where the banner view should appear.
 */
- (CGRect)rectForBannerView;

@end
