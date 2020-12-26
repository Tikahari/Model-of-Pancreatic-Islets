define(["require","exports","tslib","react","classnames","comments2/components/sticker_component/sticker_pane","comments2/components/sticker_component/sticker_tab","spectrum/icon_arrow","comments2/components/sticker_component/sticker_contants"],(function(e,t,r,s,n,c,o,a,i){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),s=r.__importStar(s),n=r.__importDefault(n);var l=(function(e){function t(t){var r=e.call(this,t)||this;return r.scrollPaneRef=s.createRef(),r.onLeftArrowPress=function(){r.setState({scrollOffset:Math.max(0,r.state.scrollOffset-i.SCROLL_DISTANCE)})},r.onRightArrowPress=function(){r.setState({scrollOffset:Math.min(r.maxScroll,r.state.scrollOffset+i.SCROLL_DISTANCE)})},r.handleChangeSelection=function(e){e!==r.state.selected&&(r.setState({selected:e}),r.resetScrollPane())},r.state={maxScroll:1,scrollOffset:0,selected:0},r}return r.__extends(t,e),t.prototype.componentDidUpdate=function(){var e=this.maxScroll;e!==this.state.maxScroll&&this.setState({maxScroll:e})},Object.defineProperty(t.prototype,"maxScroll",{get:function(){var e=this.props.stickerPacks,t=this.state,r=t.maxScroll,s=t.scrollOffset,n=s<r,c=(s>0?i.STICKER_ARROW_WIDTH:0)+(n?i.STICKER_ARROW_WIDTH:0);return Math.max(e.length*i.STICKER_TAB_ITEM_WIDTH-i.STICKER_INNER_WIDTH+c,0)},enumerable:!0,configurable:!0}),t.prototype.resetScrollPane=function(){this.scrollPaneRef.current&&(this.scrollPaneRef.current.scrollTop=0)},t.prototype.renderLeftChevronButton=function(){return s.createElement("button",{"aria-hidden":"true",className:n.default("sc-sticker-arrow","sc-sticker-arrow-left",{"sc-sticker-arrow-hide":0===this.state.scrollOffset}),tabIndex:-1,onClick:this.onLeftArrowPress},s.createElement("div",{className:"sc-sticker-arrow-container"},s.createElement(a.IconArrow,{name:"right"})))},t.prototype.renderRightChevronButton=function(){var e=this.state,t=e.scrollOffset,r=e.maxScroll;return s.createElement("button",{"aria-hidden":"true",className:n.default("sc-sticker-arrow","sc-sticker-arrow-right",{"sc-sticker-arrow-hide":t===r}),tabIndex:-1,onClick:this.onRightArrowPress},s.createElement("div",{className:"sc-sticker-arrow-container"},s.createElement(a.IconArrow,{name:"right"})))},t.prototype.renderTabs=function(e){var t="translate("+-this.state.scrollOffset+"px)";return s.createElement("div",{className:"sc-sticker-nav",role:"tablist"},this.renderLeftChevronButton(),s.createElement("div",{className:"sc-sticker-inner"},s.createElement("div",{className:"sc-sticker-inner-window",style:{transform:t}},e)),this.renderRightChevronButton())},t.prototype.render=function(){var e=this,t=this.props.stickerPacks,r=this.state.selected;if(t.length>0){var n=t.map((function(t,n){return s.createElement(o.StickerTabComponent,{key:t.id,stickerPack:t,isSelected:n===r,onClick:function(){return e.handleChangeSelection(n)}})})),a=t.map((function(t,n){return s.createElement(c.StickerPaneComponent,{key:t.id,stickerPack:t,isSelected:n===r,onStickerSelected:e.props.onStickerSelected})}));return s.createElement("div",{className:"sc-sticker-container",tabIndex:-1},this.renderTabs(n),s.createElement("div",{className:"sc-sticker-divider"}),s.createElement("div",{className:"sc-sticker-pane-scroll",ref:this.scrollPaneRef},a))}return null},t})(s.Component);t.Stickers=l}));
//# sourceMappingURL=stickers.min.js-vflCg9wcw.map