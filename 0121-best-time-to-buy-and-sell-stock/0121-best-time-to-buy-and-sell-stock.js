/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    var mini=prices[0];
    
    var n=prices.length;
    
    var profit=0;
    
    for(var i=0;i<n;i++)
        {
            mini=Math.min(mini,prices[i]);
            
            profit=Math.max(profit,prices[i]-mini);
        }
    
    return profit;
};